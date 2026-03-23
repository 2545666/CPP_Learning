#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cin >> n;
    double scores[30]; 
    double sum = 0.0;
    int fail[30];
    int fail_count = 0; 

    for (int i = 0; i < n; ++i) {
        cin >> scores[i];
        sum += scores[i];
        if (scores[i] < 60) {
             fail[fail_count++] = scores[i];
        }
    }

    double avg = sum / n;
    cout << fixed << setprecision(1) << avg << endl;

    cout << fail_count << endl;
    if (fail_count > 0) { 
        for (int i = 0; i < fail_count; i++) {
            if (i > 0) cout << " ";
            cout << fail[i];
        }
        cout << endl; 
    }

    return 0;
}