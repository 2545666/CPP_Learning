#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a,b,c;
    int s[3];
    while(cin>>a>>b>>c){
        s[0]=a,s[1]=b,s[2]=c;
        sort(s,s+3);
        int x=s[0],y=s[1],z=s[2];
        if(x+y<=z){
            cout<<"ERROR"<<endl;
            continue;
        }
        if(x==y&&y==z)
        cout<<"DB"<<endl;
        else if(x==y||y==z)cout<<"DY"<<endl;
        else if((long long)x*x+(long long)y*y==(long long)z*z)cout<<"ZJ\n";
        else cout<<"PT"<<endl;
    }
    return 0;
}