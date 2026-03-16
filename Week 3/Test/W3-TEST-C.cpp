#include <iostream>
using namespace std;

int main() 
{
   int n,a,b,c,e,f,g;
   a=0;
   b=0;
   c=0;
   cin>>n;
   for (int i=0;i<n;++i)
   {
     cin >>e>>f>>g;
     a+=e;
     b+=f;
     c+=g;
   }
   cout<<a<<" "<<b<<" "<<c<<" "<<a+b+c<<endl;
     return 0;

}