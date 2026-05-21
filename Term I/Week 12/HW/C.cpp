#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[10000];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    int max=0;
    for(int i=0;i<n;++i)
    {
       if (a[i]>max)
       {
           max=a[i];
       }
    }
    int b[max];
    for (int j=0;j<=max;++j)
    {
        b[j]=0;
    }
    for (int j=0;j<=max;++j)
    {
        for (int i=0;i<n;++i)
        {
            if (a[i]==j)
            {
                b[j]++;
            }
        }
    }
    for (int j=0;j<=max;++j)
    {
        cout<<b[j]<<endl;
    }
    return 0;
}