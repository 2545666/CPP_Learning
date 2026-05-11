#include <iostream>
using namespace std;
int main ()
{
    int a[5][5];
    for(int i=0;i<5;++i)
    {
        for(int j=0;j<5;++j)
        {
            cin>>a[i][j];
        }
    }
    int m,n;
    cin>>m>>n;
    m--;
    n--;//转为从0开始的下标
    for (int j=0;j<5;++j)//交换行
    {
        int b=a[m][j];
        a[m][j]=a[n][j];
        a[n][j]=b;
    }
    for (int i=0;i<5;++i)
    {
        for (int j=0;j<5;++j)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;//每行结束后换行
    }
    return 0;
}