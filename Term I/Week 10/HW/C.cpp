#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
    int h,n;
    cin>>h>>n;
    double res=h;
    double t=h;
    for(int i=1;i<n;++i)
    {
        t*=2.0/3;
        res+=2*t;
    }
    cout<<fixed<<setprecision(2)<<res;
    return 0;
}