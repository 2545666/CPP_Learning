#include <iostream>
using namespace std;
int com(int n)
{
    static int f=1;
    f *=n;
    return f;
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
      cout<< com(i)<<endl;
    }
}