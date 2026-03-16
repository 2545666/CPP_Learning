#include<iostream>
using namespace std;
int main()
{
    int n,a,b,c,A,B,C,SUM; //n为天数，a,b,c为单天获得金银铜牌的数量,A,B,C为累积获得数量,SUM为总数量
    cin>>n;
    A=B=C=a=b=c=0;
    for (int i=0; i<n; ++i)
    {
     cin>>a>>b>>c;
     A+=a;
     B+=b;
     C+=c;
    }
    SUM=A+B+C;
    cout<<A<<" "<<B<<" "<<C<<" "<<SUM<<" "<<endl;
    return 0;
}