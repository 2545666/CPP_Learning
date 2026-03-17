#include <iostream>
using namespace std;

int main() 
{
    int n;
    cin >> n;
    
    int max_streak = 0;  
    int t = 0;    
    
    for (int i = 0; i < n; ++i) 
     {
        int a, b;
        cin >> a >> b;
        
        if (a >= 90 && a <= 140 && b >= 60 && b<= 90) 
        {
            t++;
            if (t > max_streak) 
            {
                max_streak = t;
            }
        } 
        else 
        {
                 t = 0;
        }
    }
    cout << max_streak << endl;
    return 0;
}