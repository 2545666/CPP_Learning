#include <iostream>
using namespace std;
int main ()
{
    int n;
    cin>>n;
    int a[1000];
    int b[1000];
    int c=0;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;++i)
    {
        cin>>b[i];
    }
    for(int i=0;i<n;++i)
    {
        c+=a[i]*b[i];
    }
    cout<<c<<endl;
    return 0;
}