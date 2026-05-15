#include <iostream>
#include <string>
using namespace std;

int main() {
    string s, res;
    int max= 0, len = 0;
    char c;
    while (cin.get(c) && c != '.') {
        if (c != ' ') 
        {
            s += c;
            len++;
        } 
        else 
        {
            if (len > max) 
            {
                max = len;
                res = s;
            }
            s.clear();
            len = 0;
        }
    }
    if (len > max) 
    res = s;
    cout << res << endl;
    return 0;
}