#include <iostream>
using namespace std;

int main() {
    int k;
    cin >> k;
    
    int cnt1 = 0, cnt5 = 0, cnt10 = 0;
    int num;
    
    for (int i = 0; i < k; ++i) {
        cin >> num;
        if (num == 1) cnt1++;
        else if (num == 5) cnt5++;
        else if (num == 10) cnt10++;
    }
    
    cout << cnt1 << endl;
    cout << cnt5 << endl;
    cout << cnt10 << endl;
    
    return 0;
}