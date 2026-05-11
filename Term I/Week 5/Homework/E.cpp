/*核心：“跳”过了多少最小单元，每一维度包含的最小单元=所有子维度包含的最小单元之积
由于第一个数为0维，是最大维度，因此要注意从右往左读取，weight累乘方向从右往左，从最右边最小维度开始读取累加。
*/
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    while (cin>>n)
    {
        vector <int> a(n);
        vector <int> b(n);
        for (int i=0;i<n;++i)
        {
            cin>>a[i];
        }
        for (int i=0;i<n;++i)
        {
            cin>>b[i];
        }
    long long s=0;
    long long weight=1;
    for (int i=n-1;i>=0;--i)
    {
      s+=b[i]*weight;
      weight*=a[i];
    }
    cout<<s<<endl;
    }
    
}