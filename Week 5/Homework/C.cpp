/*本题思路：
1.双指针+交换；
2.指针定义：l为左指针，l=0；r为右指针，r=s.size()-1,这里的.size()函数为识别字符串长度的函数；
3.区分string s与string & s：
string s为普通传参：给函数发一张复印件，函数里随便改复印件，但原件一点不变
string & s为引用传参，直接把原件拿给函数改函数一改，原件直接跟着变
*/
#include <iostream>
#include <string>
using namespace std;
void trans(string&s)//使用字符串原本
{
  int left=0;//定义左指针
  int right=s.size()-1;//定义右指针
  while(left<right)//开始交换
  {
     char t=s[left];
     s[left]=s[right];
     s[right]=t;
     left++;
     right--;
  }
}
int main ()
{
    string ch;
    cin>>ch;
    trans (ch);
    cout<<ch<<endl;
    return 0;
}