 #include <iostream>
#include <vector>
using namespace std;

bool f(const vector<int>& a,int v){
    for(int x:a)if(x==v)return 1;
    return 0;
}

void p(const vector<int>& a){
    for(size_t i=0;i<a.size();++i){
        if(i)cout<<" ";
        cout<<a[i];
    }
    cout<<endl;
}

int main(){
    bool t=1;
    int m,n;
    while(scanf("%d",&m)!=EOF){
        if(!t)cout<<endl;
        t=0;
        vector<int> a(m);
        for(int i=0;i<m;++i)scanf("%d",&a[i]);
        scanf("%d",&n);
        vector<int> b(n);
        for(int i=0;i<n;++i)scanf("%d",&b[i]);
        p(a);p(b);
        for(int x:b){
            if(!f(a,x))a.push_back(x);
            p(a);
     
        }
    }
    return 0;
}