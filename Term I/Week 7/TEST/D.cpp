#include <iostream>
using namespace std;

void func(int a[], int n, int m)
{
    int t, i;
    while (m--)
    {
        t = a[n - 1];
        for (i = n - 1; i > 0; i--)
            a[i] = a[i - 1];
        a[0] = t;
    }
}

int main()
{
    int n, a[100], m, i;
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> a[i];
    cin >> m;

    func(a, n, m);

    for (i = 0; i < n; i++)
    {
        if (i) cout << " ";
        cout << a[i];
    }
    return 0;
}