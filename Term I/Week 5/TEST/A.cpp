#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    int arr[1000]; 
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    int max_len = 1;
    int current_len = 1;

    for (int i = 1; i < n; ++i) {
        if (arr[i] == arr[i-1]) 
        {
            current_len++;
        } 
        else {
            max_len = max(max_len, current_len);
            current_len = 1;
        }
    }
    max_len = max(max_len, current_len); 
    cout << max_len << endl;
    return 0;
}