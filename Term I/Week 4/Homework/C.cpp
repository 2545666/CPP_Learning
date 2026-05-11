//读取位数的方法：floor(log(m))+1
/*本题查找m中含有3的个数的方法：
1.命名一个临时变量a，避免后面第二个条件“m%19==0”时变量m被改变；
2.让a对10取模，找到当前a的最后一位数，并判断：如果最后一位数等于三，计数器就+1；
3.判断之后，让a整除10，把当前的最后一位删掉，重新进入2的操作；
4.在2和3的while循环中，得到3的数目；
//把两个条件（3的个数、整除19）进行综合判断，输出yes或no
*/
#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
    int m,k;
    int count=0;
    cin>>m>>k;
    int a=m;
    while (a>0)
    {
        int last=a%10;
        if (last==3)
        {
            count++;
        }
        a=a/10;
    }
    if (count==k && m%19==0)
    {
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    
    return 0;
}