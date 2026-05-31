#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int a,b;
    double c=0;
    while(cin>>a>>b)
    {
        if (b==0)
        {
            cout<<"error"<<endl;
            continue;
        }
        c=a*1.0/b;
        cout<<round(c)<<endl;
    }
    return 0;
}