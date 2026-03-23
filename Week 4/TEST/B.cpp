#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    int n;
    cin >> n;
    double s = 0.0, num;
    for (int i = 0; i < n; ++i) {
        cin >> num;
         s+= num;
    }
    double avg = s/n;
    cout << fixed << setprecision(4) << avg << endl;
    return 0;
}