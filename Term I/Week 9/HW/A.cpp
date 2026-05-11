#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b;
    getline(cin, a);
    getline(cin, b);//读取整串字符

    int len = min(a.size(), b.size());
    for (int i = 0; i < len; i++) 
    {
        char c1 = a[i];
        char c2 = b[i];
        int v1 = (c1 >= 'A' && c1 <= 'Z') ? c1 + 32 : c1;
        int v2 = (c2 >= 'A' && c2 <= 'Z') ? c2 + 32 : c2;//将所有字符转为小写

        if (v1 < v2) 
        {
            cout << "<" << endl;
            return 0;
        }
        if (v1 > v2) 
        {
            cout << ">" << endl;
            return 0;
        }
    }
    cout<<"="<<endl;
    return 0;
}