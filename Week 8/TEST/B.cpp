#include <iostream>
using namespace std;

int calc(int x,int y)
{
    while(y!=0)
    {
        int z=x%y;
        x=y;
        y=z;
    }
    return x;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int u,v;
        cin>>u>>v;
        cout<<calc(u,v)<<endl;
    }
    return 0;
}