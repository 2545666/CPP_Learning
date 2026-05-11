/*贪心算法：每次尽量取最优解
在本题的应用：用for循环，先让工资对最大面额整除，并计数，再让工资对最大面额取模，让工资等于余数
*/
#include <iostream>
using namespace std;
int main()
{
    int n;
    int c=0;
    int total=0;
    int model[]= {100,50,10,5,2,1};
    while(cin>>n && n!=0)
    {  int sum=0;
       for (int j=0;j<n;++j)//注意要用for循环读入每位老师的工资
       {
         int s; 
         cin>>s;
         for (int i=0;i<6;++i)
       {
         sum+=s/model[i];
         s%=model[i];
       }
       }
    total+=sum;
    }
    cout<<total<<endl;
    return 0;
}