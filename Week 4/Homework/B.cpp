/*思路：根据条件：已统计的天数+本轮要连续的天数是否不超过k，将k分为全部覆盖n的部分和剩余部分
如果未超过，本轮的n带来的金币全部计入
如果已经超过了，进入else，计入剩余天数带来的金币后，跳出循环
*/
#include <iostream>
using namespace std;
int main ()
{
    int k;
    cin>>k;
    int n=1;//本轮的连续天数
    int term=0;//已统计的天数
    int extra=0;//不完全的
    long long b=0;
    while (true)
    {
        if (term + n<=k)
        {
            b+=n*n;
            term+=n;
            n++;
        }
        else
        {
            extra=k-term;
            b+=extra*n;
            break;
        }
    }
    cout<<b<<endl;
    return 0;
}