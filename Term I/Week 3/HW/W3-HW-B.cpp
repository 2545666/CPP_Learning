#include <iostream>
using namespace std;
int main()
{
 int a,b,d;
 char c;
 cin>>a>>b>>c>>d;
 for (int i=0;i<a;++i)
 {
    for (int j=0;j<b;++j)
    {
       if (d==1)
       {
        cout<<c;
       } 
       else
       {
        if (i==0||j==0||i==a-1||j==b-1)
        {
            cout<<c;
        }
        else
        {
            cout<<" ";
        }
       }
    }
    cout<<endl;
 }
 return 0;
} 