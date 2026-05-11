//此方法用时太长
#include<iostream>
using namespace std;
int main ()
{
    int N;
    int res=0;
    cin>>N;
    for (int i=1;i<=N;++i)
    {
        for (int j=1;j<=N;++j)
        {
            for (int k=1;k<=N;++k)
            {
                if (i*j+k==N)
                res++;
            }
        }
    }
    cout<<res<<endl;
    return 0;
}