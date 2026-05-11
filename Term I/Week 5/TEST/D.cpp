#include <iostream>
using namespace std;

int main() {
    int a=0,b=0;
    int c,d;
    for(int i=1;i<=7;++i){
        cin>>c>>d;
        int e=c+d;
        if(e>8){
            if(e>a){
                a=e;
                b=i;
            }
        }
    }
    cout<<b;
    return 0;
}