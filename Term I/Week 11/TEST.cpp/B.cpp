#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class P 
{
    int x, y;

public:
    P(int a, int b) : x(a), y(b) 
    {}

    double d(P p) 
    {
        return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
    }
};

int main() 
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    
    P p1(a, b), p2(c, d);
    cout << fixed << setprecision(2) << p1.d(p2);
    
    return 0;
}