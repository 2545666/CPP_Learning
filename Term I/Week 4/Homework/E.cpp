/*本题难点：1.如何遍历从a到b的所有数——for循环
2.如何统计含有2的数的次数——末尾循环减位法
*/
#include <iostream>
using namespace std;
int main ()
{
    int a,b;
    int count=0;
    cin>>a>>b;
    int last=0;
    for (int i=a;i<=b;++i)
    {
        int num =i;
        while (num>0)
        {
            last=num%10;
            if (last==2)
            {
                count++;
            }
            num=num/10;
        }
    }
    cout<<count<<endl;
    return 0;
}