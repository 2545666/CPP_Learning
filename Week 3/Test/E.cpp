#include<iostream>
using namespace std;
int main()
{
  int k,num,c1,c5,c10;
  c1=c5=c10=0;
  cin>>k;
  for (int i=0;i<k;++i)
  {
    cin>>num;
    if (num==1)
    {
        c1++;
    }
    if (num==5)
    {
        c5++;
    }
    if (num==10)
    {
        c10++;
    }
  }
  cout<<c1<<endl;
  cout<<c5<<endl;
  cout<<c10<<endl;
  return 0;
}