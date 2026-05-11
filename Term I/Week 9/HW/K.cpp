#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m, n;
    bool first_case = true; // 控制组间空行
    while (cin >> m) { // 循环读取多组数据
        if (!first_case) {
            cout << endl; // 组与组之间输出空行
        }
        first_case = false;
        
        // 读取集合 A
        vector<int> A(m);
        for (int i = 0; i < m; ++i) {
            cin >> A[i];
        }
        
        // 读取集合 B
        cin >> n;
        vector<int> B(n);
        for (int i = 0; i < n; ++i) {
            cin >> B[i];
        }
        
        // 输出集合 A 原始数据
        for (int i = 0; i < A.size(); ++i) {
            if (i > 0) cout << " ";
            cout << A[i];
        }
        cout << "\n";
        
        // 输出集合 B 原始数据
        for (int i = 0; i < B.size(); ++i) {
            if (i > 0) cout << " ";
            cout << B[i];
        }
        cout << "\n";
        
        // 依次插入 B 的元素并输出
        vector<int> currentA = A; // 用副本操作，不影响原始A
        for (int i = 0; i < B.size(); ++i) {
            currentA.push_back(B[i]); // 插入元素到尾部
            for (int j = 0; j < currentA.size(); ++j) {
                if (j > 0) cout << " ";
                cout << currentA[j];
            }
            cout << "\n";
        }
    }
    
    return 0;
}