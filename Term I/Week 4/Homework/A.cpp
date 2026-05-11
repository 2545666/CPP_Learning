//对数组内元素排序：sort(数组名称，数组名称+数组个数)
#include<iostream>
#include<algorithm>
using namespace std;
int main ()
{
    int n,b,count;
    count=0;
    cin>>n>>b;
    int a[1000];
    int c[1000];
    for (int i=0;i<n;++i)
     {
        cin>>a[i];
     }
    for (int j=0;j<n;++j)
     {
        if (a[j]%b!=0)
        {
          c[count]=a[j];
          count++;
        }
     }
    sort(c,c+count);
    for (int t=0;t<count;++t)
     {
        if (c[t]>=65 && c[t]<=90)
        cout<<char(c[t])<<" ";
        else
        cout<<c[t]<<" ";
     }
     return 0;
}