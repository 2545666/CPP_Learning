#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a,b;
    long long total=0;
    for(int i=0;i<n;++i)
    {
        cin>>a>>b;
        total+=(long long)(a+b)*(b-a+1)/2;//求和过程必须强制转换long long型；
    }
    cout<<total;
    return 0;
}