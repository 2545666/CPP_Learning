#include <iostream>
using namespace std;
int gcd (int a,int b)
{
    while (b!=0)
    {
        int temp=a%b;
        a=b;
        b=temp;
    }
    return a;
}
int main ()
{
    int t;
    cin>>t;
    int n=0;
    while (n<t)
    {
        int a,b;
        cin>>a>>b;
        int g=gcd(a,b);
        cout<<g<<endl;
        n++;
    }
    return 0;
}