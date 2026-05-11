/*本题关键：判断区间两端的奇偶
思路，
偶数和：左是否为奇？如果是，左指针定义为a，如果不是，左指针定义为a+1；
       右是否为奇？时，右指针定义为a，如果不是，右指针定义为a—1;
三目运算——条件？a：b等价为：
if （条件）
return a；
else
return b;
*/
#include <iostream>
using namespace std;
int main()
{
    int a,b,s1,s2;
    s1=s2=0;
    int l,r;
    cin>>a>>b;
    l=a;
    r=b;
    int fe=(l%2==0)?l:l+1;
    int le=(r%2==0)?r:r-1;
    for (int i=fe;i<=le;i+=2)
    {
        s1+=i;
    }
    int fo=(l%2==1)?l:l+1;
    int lo=(r%2==1)?r:r-1;
    for (int i=fo;i<=lo;i+=2)
    {
        s2+=i;
    } 
    cout <<s1<<" "<<s2<<endl;
    return 0;
}