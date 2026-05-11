#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
 int n;
 cin>>n;
double counti,count;
 counti=count=0;
for (int i=1;i<=n;++i)
{
 counti = pow(-1,i-1)*1.0/i;
 count +=counti;
}
cout<<fixed<<setprecision(4)<<count<<endl;
 return 0;
} 