#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int t=0;
    int k=0;
    int m=0;
    while (t<n)
    {
        int a,b;
        cin>>a>>b;
        if (a==b)
        {
            k++;
            if (k>m)
            m=k;
        }
        if (a!=b)
        {
            k=0;
        }
        t++;
    }
    if (m>=3)
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;
    return 0;
}