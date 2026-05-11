#include <iostream>
#include <cmath>
using namespace std;
int main()
{
int n,counti,count;
cin>>n;
counti=1;
count=0;
for (int i=1;i<=n;++i)
{
    counti*=i;
    count+=counti;
}
cout<<count<<endl;
 return 0;
} 