#include <iostream>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int cnt=1;
    while(n>=m)
    {
        n=n/m;
        cnt++;
    }
    cout<<cnt<<endl;
    return 0;
    
}