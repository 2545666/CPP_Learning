#include <iostream>
using namespace std;
int main () {
int a;
int b;
int sum;
sum=0;
cin>>a>>b;
if (a<b)
cout<<"偶数之和："<<endl;
else
cout<<"error"<<endl;
int i=a;
while (i<=b)
 {
 if (i%2==0)
  {
 sum+=i;
  } 
i++;
}
 cout<<sum<<endl;
 return 0;
}