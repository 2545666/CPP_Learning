 /*1.本题需注意：若一个数num可以由两个质数a，b相乘得到，那么它的公因数只有1，a，b，num
 2.同时遍历环节，让i从最小的质数2开始遍历，由对称性可知，只需从2到sqrt(num)即可；
 3.设置条件，根据1的性质，除了1和本身外，只有这两个质数a、b能被num整除，因此只需设定条件，当遍历到能被num整除时，跳出循环，此时的i即为较小的质数a，num/a就是较大的质数b。
 */
 #include<iostream>
 #include<cmath>
 using namespace std;
int main ()
{
    long long num=0;
    long long min =0;
    long long max =0;
    cin>>num;
    for (long long i =2; i<=sqrt(num);++i)
    {
        if (num%i==0)
        {
            max=num/i;
            break;
        }
    }
    cout<<max<<endl;
    return 0;
}