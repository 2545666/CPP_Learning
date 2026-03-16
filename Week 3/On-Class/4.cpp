#include <iostream>
using namespace std;
int main () {
int a;
int b;
cin>>a>>b;
if (a<b)
cout<<"偶数："<<endl;
else
cout<<"error"<<endl;
int i=a;
while (i<=b)
{
 if (i%2==0)
 {
 cout<<i<<endl;
 i++;
 }
 return 0;
}
}
