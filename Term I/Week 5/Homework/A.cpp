/*素数判定规则（所有正整数）：
1.小于2的不是；
2.2是素数；
3.大于二的偶数不是；
4.大于二的奇数：
   由于因数是成对存在的，
   故只需要查一半即可，
   从最小的奇数3，遍历所有奇数，一直到sqrt（n），n为要判断的数，判断sqrt（n）能否被整除
   判断方法，从3一直遍历所有数到sqrt（n），一旦发现n能被i整除，返回false。
*/
#include <iostream>
#include <cmath>
using namespace std;
bool test(int n)
{
  if (n<2)
  return false;
  if (n==2)
  return true;
  if (n>2&&n%2==0)
  return false;
  if (n>2)
  {
    for (int i=3;i<sqrt(n);i+=2)
    {
      if (n % i==0)
      return false;
    }
    return true;
  }
}
int main ()
{
    int num;
    cin>>num;
    if (test(num))
    cout<<"prime"<<endl;
    else
    cout<<"not prime"<<endl;
    return 0;
}