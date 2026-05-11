#include <iostream>
using namespace std;
void odd (int a)
{
  if (a%2==0)
  cout <<"偶数"<<endl;
  else
  cout <<"奇数"<<endl;
}
int main ()
{
    int a;
    cin>>a;
    odd(a);
    return 0;
}