#include <iostream>
using namespace std;
int main() {
    int a,b,c,t;
    cin>>t;
    a=t/100;
    b=(t%100)/10;
    c=t%10;
    if (t==(a*a*a+b*b*b+c*c*c))
        cout<<"1"<<endl;
    else
        cout<<"0"<<endl;
    return 0;
}