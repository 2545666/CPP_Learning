#include <iostream>
using namespace std;
class time 
{
    private:
      int hour;
      int minute;
      int second;
    public: 
      void setTime(int h, int m, int s) 
      {
        hour = (h >= 0 && h < 24) ? h : 0;
        minute = (m >= 0 && m < 60) ? m : 0;
        second = (s >= 0 && s < 60) ? s : 0;
      }
      Clock(int h = 0, int m = 0, int s = 0) 
      {
        setTime(h, m, s);
      }
      void tick() 
      {
        second++; // 秒 +1

        // 秒进位到分
        if (second >= 60) {
            second = 0;
            minute++;

            // 分进位到时
            if (minute >= 60) {
                minute = 0;
                hour++;

                // 时进位到 0 点
                if (hour >= 24) {
                    hour = 0;
                }
            }
        }
    }

};