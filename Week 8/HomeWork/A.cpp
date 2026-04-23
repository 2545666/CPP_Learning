/*题目要求找到的最大求和，也就是(A-a)+(B-b),拆一下括号，也就是（A+B）-（a+b），即：无需考虑第一最大值和第一最小值是否在一个圆弧上，只要找到包含最大值和最小值的圆弧，就能找到要求的子数组
这四个值会在圆环上分布，把圆环分成四个圆弧，总能找到两个相异圆弧，使得这两个圆弧的两端分别为最大值和最小值
那么，如何找出第一最大值A和第二最大值B，第一最小值a和第二最小值b？
使用排序sort函数，引入algorithm即可。
sort函数怎么用？
sort(数组首地址（即数组名），数组最后一个元素地址，排序规则（默认从小到大，如果从大到小：greater<int>())*/
#include <iostream>
#include <algorithm>
using namespace std;
int main ( )
{
    int t,n;
    cin>>t;
    int a[110];
    int c=0;
    while(c<t)
    {
      cin>>n;
      for (int i=0;i<n;++i)
      {
        cin>>a[i];
      }
      sort(a,a+n);
      int maxa=a[n-1];
      int maxb=a[n-2];
      int mina=a[0];
      int minb=a[1];
      long long ans= (maxa+maxb)-(mina+minb);
      cout<<ans<<endl;
      c++;
    }
    return 0;
}