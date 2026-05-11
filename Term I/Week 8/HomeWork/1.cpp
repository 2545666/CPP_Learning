#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    int n,b;
    cin>>n>>b;
    int a[100];
    char c[100];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;++i)
    {
        if (a[i]%b!=0)
        c[i]=a[i];
    }
    sort(c,c+n);
    for(int i=0;i<n;++i)
    {
        if(c[i]>=65&&c[i]<=91)
        {
            c[i]=(char)c[i];
        }
    }
    for(int i=0;i<n;++i)
    {
        cout<<c[i]<<" ";
    }
    return 0;
}