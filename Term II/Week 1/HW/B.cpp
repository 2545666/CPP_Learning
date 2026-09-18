#include<iostream>
using namespace std;
int main()
{
    int a=0;
    int b=0;
    int c=0;
    int f[5];
    for (int i=0;i<5;++i)
    {
        cin>>f[i];
        if(f[i]==1)
        {
            a++;
        }
        if(f[i]==2)
        {
            b++;
        }
          if(f[i]==3)
        {
            c++;
        }
    }
    int ans=0;
    int odd=0;
    if(a%2==1)
    {
        odd++;
        ans=1;
    }
    if(b%2==1)
    {
        odd++;
        ans=2;
    }
    if(c%2==1)
    {
        odd++;
        ans=3;
    }
    if(odd!=1)
    {
        ans=0;
    }
    cout<<ans;
    return 0;
}