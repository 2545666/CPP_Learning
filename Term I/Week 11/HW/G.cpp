#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    getline(cin,s);
    int len=s.size();
    for(int i=0;i<len;++i)
    {
        if(s[i]!=' '&&s[i]!='.')
        {
            if((int)s[i]>=65&&(int)s[i]<=90)
            {
                s[i]=s[i]+'a'-'A';
            }
             else if((int)s[i]>=97&&(int)s[i]<=122)
            {
                s[i]=s[i]-'a'+'A';
            }
        }
    }
    cout<<s<<endl;
    return 0;
}