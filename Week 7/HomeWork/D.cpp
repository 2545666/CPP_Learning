#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
void func1(float a,float b,float c)
{
   float delta= b*b-4*a*c;
   float x1=(-b+sqrt(delta))/(2*a);
   float x2=(-b-sqrt(delta))/(2*a);
   cout<<"x1="<<fixed<<setprecision(3)<<x1<<" "<<"x2="<<fixed<<setprecision(3)<<x2<<endl;
}

void func2(float a,float b,float c)
{
    float x= -b/(2*a);
    cout<<"x="<<fixed<<setprecision(3)<<x<<endl;
}

void func3(float a,float b,float c)
{
    float delta= b*b-4*a*c;
    float real=-b/(2*a);
    float imag=sqrt(-delta)/(2*a);
    cout<<"x1="<<fixed<<setprecision(3)<<real<<"+"<<fixed<<setprecision(3)<<imag<<"i"<<" "<<"x2="<<fixed<<setprecision(3)<<real<<"-"<<fixed<<setprecision(3)<<imag<<"i"<<endl;
}

int main ()
{
    float a,b,c;
    cin>>a>>b>>c;
    float delta= b*b-4*a*c;
    if (delta>0)
    func1(a,b,c);
    if (delta==0)
    func2(a,b,c);
    if (delta<0)
    func3(a,b,c);
    return 0;
}