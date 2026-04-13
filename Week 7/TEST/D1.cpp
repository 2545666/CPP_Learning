#include <iostream>
using namespace std;
void shift(int a[],int n,int m)
{
    int temp[101];//开辟临时数组，存储数组里后m个数
    for (int i=0;i<m;++i)
    {
        temp[i]=a[n-m+i];
    }
    for (int i=n-1;i>=m;--i)//从后往前覆盖
    {
        a[i]=a[i-m];
    }
    for (int i=0;i<m;++i)//把临时数组中的数存入当前数组的前m个数中
    {
        a[i]=temp[i];
    }
}
int main()
{
    int n,m;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    cin>>m;
    shift (a,n,m);
    for(int i=0;i<n-1;++i)
    {
        cout<<a[i]<<" ";
    }
    cout<<a[n-1];
}