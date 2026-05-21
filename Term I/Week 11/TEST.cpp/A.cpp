#include <iostream>
#include <string>
using namespace std;

int main() {
    string a;
    cin >> a;

    if (a.size() > 1) {
        string b = a.substr(a.size() - 2);
        
        if (b == "er" || b == "ly") {
            a = a.substr(0, a.size() - 2);
        } else if (a.size() > 2 && a.substr(a.size() - 3) == "ing") {
            a = a.substr(0, a.size() - 3);
        }
    }

    cout << a;
    return 0;
}