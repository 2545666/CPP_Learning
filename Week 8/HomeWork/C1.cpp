#include <iostream>
#include <string>
using namespace std;

int main()
{
    //1.识别输入
    string a, b, t;//三个字符串，a为加密表的密文，b为加密表原文，t为要破译的字符串
    cin >> a >> b >> t;
    //2.定义两个数组
    char m[26] = {0};//初始化，密文➡️原文（解密用）
    char n[26] = {0};//原文➡️密文（防冲突用）
    bool ok = 1;

    for (int i = 0; i < a.size(); i++)
    {
        int x = a[i] - 'A';//将加密字符的ASCII码转化为0-25的数字
        int y = b[i] - 'A';//将原文字符的ASCII码转化为0-25的数字
        m[x] = b[i];
        n[y] = a[i];//将a，b中对应的字符分别存入数组中
        if (m[x] != 0 && m[x] != b[i]) //如果x已经存过，且对应的值不是y → 冲突=不合法
        ok = 0;
        if (n[y] != 0 && n[y] != a[i]) //如果y已经存过，且对应的值不是x → 冲突=不合法
        ok = 0;
    }

    int cnt = 0;
    for (int i = 0; i < 26; i++)
        if (m[i] != 0) 
        cnt++;//遍历获取存入的有效字符数
    if (cnt != 26) //保证存入26个字母
    ok = 0;

    if (!ok)
        cout << "Failed" << endl;
    else
    {
        string s;//用于存放结果
        for (int i = 0; i < t.size(); i++)
        {
            char ch = t[i];//把需要翻译的字符一个个拿出来
            s += m[ch - 'A'];//进行字符拼接
        }
        cout << s << endl;
    }

    return 0;
}