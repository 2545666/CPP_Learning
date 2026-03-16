#include <iostream>
#include <cmath>
using namespace std;

int main() {
   int num,a,b,c,d,e,f;
   cin>>num;
   a=num/10000;
   b=(num%10000)/1000;
   c=(num%1000)/100;
   d=(num%100)/10;
   e=(num%10);
   f= floor(log10(num)) + 1;
cout<<f<<endl;
cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<endl;
cout<<e<<d<<c<<b<<a<<endl;
    return 0;
}