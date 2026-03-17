#include <iostream>
using namespace std;
int main()
{
 int n, a, b, c, m; //c为连续时间，m为历史最长时间
 cin>>n;
 a=b=c=m=0;
 for (int i=0;i<n;++i)
 {
    cin>>a>>b;
    if (a>=90 && a<=140 && b>=80 && b<=90)
    {
      c++;
      if (c>m)
      m=c;//更新历史最大值
    }
    else
    {
    c=0; //条件不符，连续值清零
    }
 }
 cout<<c<<endl;
 return 0;
} 
