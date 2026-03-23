#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
 int n;
 cin>>n;
 int a[1000];
 for (int i=0;i<n;++i)
 {
   cin>>a[i];
 }
 int max = *max_element (a,a+n);
 int min = *min_element (a,a+n);
 int span=max-min;
 cout<<span<<endl;
 return 0;
} 