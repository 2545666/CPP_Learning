#include <iostream>
using namespace std;

int main() {
    int num[20];
    for (int i = 0; i < 20; ++i) {
        cin >> num[i];
    }
    for (int i = 19; i >= 0; --i) 
    {
        if (i < 19) cout << " ";  
        cout << num[i];
    }
    cout << endl;
    return 0;
}