#include <iostream>
using namespace std;

void input(int a[], int n) {
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
}
void p(int a[], int n) {
    int min = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] < a[min]) {
            min = i;
        }
    }
    int temp1=a[min];
    a[min]=a[0];
    a[0]= temp1;
    int max = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] > a[max]) {
            max = i;
        }
    }
     int temp2=a[max];
    a[max]=a[n-1];
    a[n-1]= temp2;
}
void output(int a[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
}

int main() {
    const int N = 10;
    int a[N];

    input(a, N);
    p(a, N);
    output(a, N);

    return 0;
}