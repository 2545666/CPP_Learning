#include <iostream>
using namespace std;

int main() {
    int budget[12];
    // 输入12个月的预算
    for (int i = 0; i < 12; ++i) {
        cin >> budget[i];
    }

    int current = 0;    // 当前手中现金
    int save = 0;       // 存在妈妈那里的总钱数
    int month;

    for (month = 1; month <= 12; ++month) 
    {
        // 1. 月初收到妈妈给的300元
        current += 300;

        // 2. 检查是否够本月预算
        if (current < budget[month-1]) 
        {
            // 钱不够，输出 -月份
            cout << -month << endl;
            return 0;
        }

        // 3. 按预算消费
        current -= budget[month-1];

        // 4. 计算要存的整百钱
        int save_this = (current / 100) * 100;
        if (save_this >= 100) 
        {
            save += save_this;
            current -= save_this;
        }
    }

    // 5. 年末妈妈返还储蓄（+20%）
    current += save * 1.2;

    // 输出年末总钱数
    cout << current << endl;
    return 0;
}