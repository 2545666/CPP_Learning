#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    bool k[101] = {};
    int f, g, h = 0;
    for (f = 2; f <= 100; f++) {
        if (!k[f]) {
            for (g = f * 2; g <= 100; g += f)
                k[g] = 1;
        }
    }
    for (f = 2; f <= 100; f++) {
        if (!k[f]) {
            cout << setw(5) << f;
            h++;
            if (h % 5 == 0)
                cout << endl;
        }
    }
    return 0;
}