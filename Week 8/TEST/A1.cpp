#include <iostream>
#include <cmath>
using namespace std;
int main () {
    int a,b,c;
    while (cin>>a>>b>>c){
        if (a+b<=c||a+c<=b||b+c<=a)
        cout<<"ERROR"<<endl; else {
        if (a==b&&b==c)
            cout<<"DB"<<endl; else if (a==b &&a==c&&b==c||b==c &&a==b&&a==c||a==c &&b==c&&a==b)
        cout<<"DY"<<endl; else if (a==sqrt(b*b+c*c)||b==sqrt(a*a+c*c)||c==sqrt(b*b+a*a))
        cout<<"ZJ"<<endl; else
            cout<<"PT"<<endl;
        }
    }
    return 0;
}