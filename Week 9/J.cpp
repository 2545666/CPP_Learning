#include<iostream>
using namespace std;
int main ()
{
    int n,q;
    cin>>n>>q;
    int m=0;
    if (n<10)
    {
      m=q+100*(10-n) ;
    }
    else if(n>=10)
    {
        m=q;
    }
    cout<<m<<endl;
}