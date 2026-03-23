#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long fact = 1;
    long long sum = 0;
    const int MOD = 1000000;
    int max_i = min(n, 24);
    for (int i = 1; i <= max_i; ++i) {
        fact = (fact * i) % MOD;
        sum = (sum + fact) % MOD;
    }
    cout << sum << endl;
    return 0;
}