#include <iostream>
using namespace std;

struct Complex{
    int r,i;
};

Complex add(Complex a,Complex b){
    return {a.r+b.r, a.i+b.i};
}
Complex mul(Complex a,Complex b){
    return {a.r*b.r-a.i*b.i, a.r*b.i+a.i*b.r};
}
void print(Complex x){
    if(x.i>=0) cout<<x.r<<"+"<<x.i<<"i";
    else cout<<x.r<<"-"<<-x.i<<"i";
}

int main(){
    int n; cin>>n;
    Complex s={0,0},p={1,0},t;
    for(int i=0;i<n;i++){
        cin>>t.r>>t.i;
        s=add(s,t);
        p=mul(p,t);
    }
    cout<<"Sum=";print(s);cout<<endl;
    cout<<"Product=";print(p);cout<<endl;
    return 0;
}
