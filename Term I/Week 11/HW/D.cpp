#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int b=0;
    for(int i=1;i<10000;++i)
    {
        if ((i*i+i)/2-n>0 && ((i*i+i)/2-n)%3==0)
        {
            b=i;
            break; 
        }
    }
    int a=((b*b+b)/2-n)/3;
    cout<<a<<" "<<b;
    return 0;
}