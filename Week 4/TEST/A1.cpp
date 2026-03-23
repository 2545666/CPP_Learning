#include <iostream>
using namespace std;
int main ()
{
  int n;
  cin>>n;
  long long num=1;
  long long sum=0;
  for (int i=1;i<=n;++i)
  {
    num*=i;
    sum+=num%100000;
  }
  int res=sum%100000;
  cout<<res<<endl;
 return 0;
}