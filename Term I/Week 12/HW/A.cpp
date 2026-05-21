#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main ()
{
    double xa,ya,xb,yb;
    cin>>xa>>ya;
    cin>>xb>>yb;
    double dis=sqrt(pow(xa-xb,2)+pow(ya-yb,2));
    cout<<fixed<<setprecision(3)<<dis<<endl;
    return 0;
}