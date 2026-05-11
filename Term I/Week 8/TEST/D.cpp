#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }

    bool f = 0;
    for (int i = 0; i <= n - 3; ++i) {
        if (a[i].first == a[i].second &&
            a[i+1].first == a[i+1].second &&
            a[i+2].first == a[i+2].second) {
            f = 1;
            break;
        }
    }

    cout << (f ? "Yes" : "No") << endl;
    return 0;
}