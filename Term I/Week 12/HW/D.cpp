#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int c[100];
    for (int i=0;i<100;++i)
    {
        c[i]=0;
    }
    for (int i=1;i<=n;++i)
    {
        int a=i/10;
        int b=i%10;
        if((i%7!=0)&&(a!=7)&&(b!=7))
        {
            c[i]=i;
        }
    }
    int len=sizeof(c)/sizeof(c[0]);
    int res=0;
    for (int i=1;i<len;++i)
    {
        res+=pow(c[i],2);
    }
    cout<<res<<endl;
}