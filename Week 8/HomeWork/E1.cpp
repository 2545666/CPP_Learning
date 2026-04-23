/*短时间算法：a*b+c=N有多少种结果
c=N-a*b>=1,故只需找出所有满足a*b<=N-1的所有a，b组合即可，也就是找出满足b<=(N-1)/a条件的所有b的值的个数，b为大于一的正实数，因此(N-1)/a的结果就是个数
*/
#include <iostream>
using namespace std;
int main ()
{
    int N;
    cin>>N;
    int res=0;
    for (int i=1;i<=N;++i)
    {
        res+= (N-1)/i;
    }
    cout<<res;
    return 0;
}