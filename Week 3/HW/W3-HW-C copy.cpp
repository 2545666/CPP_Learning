#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
int n;
double x,counti,count;
cin>>x>>n;
counti=count=0;
for (int i=0;i<=n;++i)
{
    counti=pow(x,i);
    count += counti;
}
cout<<fixed<<setprecision (2)<<count<<endl;
 return 0;
} 