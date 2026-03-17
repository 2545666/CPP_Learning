#include<iostream>
using namespace std;
int main()
{
  int budget[12];
  for (int i=0;i<12;++i)
  {
    cin>>budget[i];
  }

int money;//现在手里的钱
int save; //存在妈妈那里的钱
int month;

for (month=1;month<=12;++month)
{
    money+=300;//月初给300
    if (money < budget[month-1]) 
        {
            // 钱不够，输出 -月份
            cout << -month << endl;
            return 0;
        }

        // 按预算消费
        money -= budget[month-1];

        // 计算要存的整百钱
        int save_this = (money / 100) * 100;
        if (save_this >= 100) 
        {
            save += save_this;
            money -= save_this;
        }
    }

    // 年末妈妈返还储蓄（+20%）
    money += save * 1.2;

    // 输出年末总钱数
    cout << money << endl;
    return 0;
}