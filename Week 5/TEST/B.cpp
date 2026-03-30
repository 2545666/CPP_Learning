#include <iostream>
using namespace std;

int main() {
    int row1[5], row2[5], row3[5], row4[5], row5[5];
    for (int j = 0; j < 5; j++) cin >> row1[j];
    for (int j = 0; j < 5; j++) cin >> row2[j];
    for (int j = 0; j < 5; j++) cin >> row3[j];
    for (int j = 0; j < 5; j++) cin >> row4[j];
    for (int j = 0; j < 5; j++) cin >> row5[j];
    
    int m, n;
    cin >> m >> n;
    int* rows[5] = {row1, row2, row3, row4, row5};
    int* temp = rows[m-1];
    rows[m-1] = rows[n-1];
    rows[n-1] = temp;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (j > 0) cout << " ";
            cout << rows[i][j];
        }
        cout << endl;
    }
    
    return 0;
}