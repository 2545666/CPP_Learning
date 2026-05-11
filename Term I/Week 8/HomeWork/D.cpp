/*怎么把环状字符串转为线性字符串？
方法：将字符串加倍即可
判断是否相等时要注意遍历，不等再跳出循环
环状字符串两个注意点：
1.用线性字符串遍历时需加倍；
2.起点未定，需要遍历所有起点
*/
#include<iostream>
#include<string>
using namespace std;
int main ()
{
    string a,b,A,B;
    cin>>a>>b;
    A=a+a;
    B=b+b;
    int m=a.size();
    int n=b.size();
    int res=0;
    for (int i=0;i<m;++i)//A环起点
    {
        for(int j=0;j<n;++j)//B环起点
        {
            int count =0;
            while(A[i+count]==B[j+count]&&i+count<A.size()&&j+count<B.size())//开始遍历，一旦遇到不同就跳出while循环，开始新的起点
            {
                count++;
            }
            if(count>res)
            res=count;
        }
    }
/*注意！这是单起点的方法，并未遍历多个起点
    int len;
    if (A.size()<B.size())
    len=A.size();
    else
    len=B.size();
    int count=0;
    int max=0;
     for (int i=0;i<len;++i)
    {
        if (A[i]==B[i])
        {
            count ++;
            if (count>max)
            max=count;
        }
        else
        count=0;
    }
    cout<<max<<endl;*/
    cout<<res<<endl;
    return 0;
}