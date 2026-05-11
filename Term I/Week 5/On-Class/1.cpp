#include <iostream>
using namespace std;
int main ()
{
    int size;
    cin>>size;
    int *a= new int [size];//向计算机申请能放size个int的空间，返回这段空间的起始地址
    for (int i=0; i<size;++i)
    {
        cin>>a[i];
    }
    for (int i=size-1;i>=0;--i)
    {
        cout<<a[i];
    }
    delete [] a;
    return 0;


}