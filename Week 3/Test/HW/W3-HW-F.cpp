#include <iostream>
#include <cmath>
using namespace std;
int main()
{
int h,n;
cin>>h;
double counti=h;
double count=h;
double count10;
for (int i=1;i<=9;++i)
{
    counti=h*pow(0.5,i);
    count +=counti*2;
}
    count10=h*pow(0.5,10);
    cout<<count<<endl;
    cout<<count10<<endl;
 return 0;
} 