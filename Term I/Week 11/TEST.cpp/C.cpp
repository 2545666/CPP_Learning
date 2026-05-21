#include <iostream>
#include <cstring>
using namespace std;

class M
{
    char* s;

public:
    M(const char* p)
    {
        int l = strlen(p);
        s = new char[l + 1];
        memcpy(s, p, l + 1);
    }

    ~M()
    {
        delete[] s;
    }

    int g() const
    {
        return strlen(s);
    }

    void p() const
    {
        cout << s << endl;
    }
};

int main()
{
    char b[101];
    cin >> b;
    M a(b);

    cout << a.g() << endl;
    a.p();

    return 0;
}