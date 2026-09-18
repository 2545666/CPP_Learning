#include <iostream>
#include <iomanip>
using namespace std;
int main ()
{
    int a,b,c,d,e,f,g,h,i,j;
    cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j;
    double res;
    res=a*28.9+b*32.7+c*45.6+d*78+e*35+f*86.2+g*27.8+h*43+i*56+j*65;
    cout<<fixed<<setprecision(1)<<res<<endl;
    return 0;
}