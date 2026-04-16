/* 字符串 char a[]可作为数组进行索引和修改
*/
#include <iostream>
#include <string>
using namespace std;
void func (int n, int m, char a[],char b[])
{
    for(int i=m-1;i<n;++i)
   {
     b[i-m+1]=a[i];
   }
}
int main ()
{
    int m,n;
    char a[100];
    char b[100];
    cin>>n;
    cin>>a;
    cin>>m;
    func(n,m,a,b);
    cout<<b<<endl;
    return 0;
}