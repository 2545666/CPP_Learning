#include <iostream>
using namespace std; 
int main ()
{
    int n,m,num,c;
    c=0;
    cin>>n>>m;
    for (int i=0;i<n;++i)
    {
     cin>>num;//把序列输入放入循环中，依次读入输入的数，再进行判断 
     if (num==m)
     {
        c++;
     }
    }
    cout<<c<<endl;
    return 0;
}