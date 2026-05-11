#include <iostream>
using namespace std;
void trans(int m[3][3])
{
  for (int i=0;i<3;++i)//从0开始遍历！！！
  {
    for (int j=i+1;j<3;++j)//只遍历上三角，避免重复交换
    {
    int t=m[i][j]; //把矩阵当前的值复制到临时变量t一份
    m[i][j]=m[j][i];//把j，i的值赋给i，j
    m[j][i]=t;//把i，j的值赋给j，i
    }
  }
}
int main ()
{
  int mat[3][3];
  for (int i=0;i<3;++i)
  {
    for (int j=0;j<3;++j)
    cin>>mat[i][j];
  }
  trans(mat);
  for (int i=0;i<3;++i)
  {
    for (int j=0;j<3;++j)
    cout<<mat[i][j]<<" ";
    cout<<endl;
  }
  
return 0;
}