#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class S
{
    string i;
    double s;
    static double t;
    static int c;

public:
    S(string a, double b) : i(a), s(b)
    {
        t += b;
        c++;
    }

    static double g()
    {
        return c ? t / c : 0;
    }
};

double S::t;
int S::c;

int main()
{
    int n;
    cin >> n;

    for (int j = 0; j < n; j++)
    {
        string a;
        double b;
        cin >> a >> b;
        S(a, b);
    }

    cout << fixed << setprecision(2) << S::g();
    return 0;
}