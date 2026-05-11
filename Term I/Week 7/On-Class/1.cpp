#include <iostream>
using namespace std;
int com(int *x,int *y)
{
    if (*x>*y)
    return *x;
    else
    return *y;
}
int main()
{
   int a,b;
   cin>>a>>b;
   cout<<com(&a,&b);
   return 0;
}