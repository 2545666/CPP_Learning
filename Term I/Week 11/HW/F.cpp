/*1. 语法细节类
成员函数调用必须加()：getLength()/print()少写括号，编译器会把函数名当成 “函数指针”，而非 “调用函数”，触发 “invalid use of non-static member function” 错误；
变量作用域要分清：构造函数的参数s只在构造函数内有效，其他成员函数（如print()）不能直接用，要访问类的私有成员（如str）而非跨函数用参数。
2. 数据类型类（字符串相关核心坑）
string和const char*不能直接转换：构造函数接收const char*（C 风格字符串）时，若传入string（C++ 字符串），必须用c_str()方法转换（s.c_str()），否则触发 “no matching function” 类型不匹配报错；
C 风格字符串必须留'\0'空间：动态分配内存时要new char[length + 1]，+1是为字符串结束符'\0'预留位置，否则会内存越界；
char*指针的特殊打印规则：cout << char*不会打印地址，而是从指针指向的地址开始打印字符直到'\0'，这是 C++ 对字符串指针的专属处理。
3. 类与内存管理类（面向对象核心）
构造函数自动调用：创建对象MyString str(...)时，编译器会自动调用对应参数的构造函数，无需手动写str.MyString(...)；
动态内存必须释放：用new[]分配的内存，要在析构函数中用delete[]释放，析构函数不影响输出结果，但能防止内存泄漏；
指针赋值的本质：char* str是指针，赋值str = new char[...]是把 “新内存的首地址” 存到指针里，而非直接存字符串内容。
*/
#include<iostream>
#include<cstring>
using namespace std;
class MyString
{
    private:
    char* str;
    int length;
    public:
    MyString(const char* s)
    {
        length=strlen(s);
        str=new char [length+1];
        strcpy(str,s);
    }
    ~MyString()
    {
        delete[] str;
        str=nullptr;
    }
    void print ()
    {
        cout<<str<<endl;
    }
    int getLength()
    {
        return length;
    }
};
int main()
{
    char s[101];
    cin>>s;
    MyString str(s);
    cout<<str.getLength()<<endl;
    str.print();
    return 0;
}