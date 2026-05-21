#include <iostream>
using namespace std;
int main()
{
    int m;
    cin>>m;
    int n;
    cin>>n;
    int a[100];
    for(int i=0;i<100;++i)
    {
        a[i]=0;
    }
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    int res=0;
    for(int i=0;i<n;++i)
    {
        if (m>=a[i])
        {
          m-=a[i];
        }
        else
        {
           res++; 
        }
    }
    cout<<res<<endl;
    return 0;
}