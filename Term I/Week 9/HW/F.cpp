#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;//cin读取连续字符串，遇到空格/换行停止；getline(cin,s)读取完整字符串，遇到换行停止。
    for(int i=0;i<s.size();++i)
    {
        if (s[i]=='o')
        {
            k++;
        }
        if(s[i]=='x')
        {
            if(k!=0)
            {
                k--;
            }
        }
    }
    cout<<k;
    return 0;
}