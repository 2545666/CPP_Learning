#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    string s;
    cin>>s;
    reverse(s.begin(),s.end());
    for(char c:s)
    {
        cout<<c<<" ";
    }
    return 0;
    
}