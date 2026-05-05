#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    string s;
    cin>>s;
    for(int i=0;i<s.size();++i)
    {
        if (s[i]>='A'&&s[i]<='Z')
        {
            s[i]=s[i]+32;
        }
        else if (s[i]>='a'&&s[i]<='z')
        {
            s[i]=s[i]-32;
        }
    }
    reverse(s.begin(),s.end());
    for(int i=0;i<s.size();++i)
    {
        if (s[i] >= 'A' && s[i] <= 'Z') 
        {
            s[i] = (s[i] - 'A' +3 + 26) % 26 + 'A';
        } 
        else if (s[i] >= 'a' && s[i] <= 'z') 
        {
            s[i] = (s[i] - 'a' + 3 + 26) % 26 + 'a';
        }
    }
    
    
    for(int i=0;i<s.size();++i)
    {
        cout<<s[i];
    }
    return 0;
    
}