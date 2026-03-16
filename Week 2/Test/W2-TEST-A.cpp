#include <iostream>
#include<iomanip>
using namespace std;
int main()
{
    float r,h;
    cin>>r>>h;
    float C1= 2*3.14*r;
    float Sa=3.14*r*r;
    float Va= 4*3.14*r*r*r/3;
    float Vb=Sa*h;
    cout<<fixed<<setprecision(2)<<C1<<endl;
    cout<<fixed<<setprecision(2)<<Sa<<endl;
    cout<<fixed<<setprecision(2)<<Va<<endl;
    cout<<fixed<<setprecision(2)<<Vb<<endl;
    return 0;
}
