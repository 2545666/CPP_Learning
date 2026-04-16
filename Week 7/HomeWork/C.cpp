/*最小公倍数（Leastest Commen Multiple）LCM
  最大公因数（Greastest Commen Divide) GCD
  任意两数a，b，永远满足：LCM*GCD=a*b;
  故只用求GCD即可求得LCM；
  如何球GCD？
  欧几里得算法：辗转相除
  余数=大数%小数
  把小数赋值给大数，把余数赋值给小数
  标准算法：
  while (b!=0)
  {
     int temp =a%b;
     a=b;
     b=temp;
  }
     此算法无需考虑ab大小，因为当a小于b，a%b=a, a=b，就把大数自动赋给a了
*/
#include <iostream>
using namespace std;
int gcd(int a,int b)
{
   int temp =1;
    while(b!=0)
    {
        temp= a % b;
        a=b;
        b=temp;
    }
    return a;
}
int main ()
{
    int a,b;
    cin>>a>>b;
    int g= gcd(a,b);
    int lcm= a*b/g;
    cout<<g<<" "<<lcm<<endl;
    return 0;
}