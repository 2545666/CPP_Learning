#include<iostream>
using namespace std;
void input(int a[],int n)
{
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
}
void process(int a[],int n)//重新定义局部变量
{
     int min=0;
     int max=0;
    for (int i=0;i<n;++i)
    {
        if (a[i]<a[min])
        {
            min=i;//!!!只改地址，不改值！
        }
    }
    
    int temp1=a[min];
    a[min]=a[0];
    a[0]=temp1;
    for (int i=0;i<n;++i)
    {
        if (a[i]>a[max])
        {
            max=i;
        }
    }

    int temp2=a[max];//交换
    a[max]=a[n-1];
    a[n-1]=temp2;
}
void output(int a[],int n)
{
    for(int i=0;i<n;++i)
    {
        cout<<a[i]<<" ";
    }
}

int main ()
{
    int const N=10;
    int a[N];
    input(a,N);
    process(a,N);
    output(a,N);
}