#include <iostream>
using namespace std;
int func(int a, int b)
{
    return a + b;
}

int main()
{
    int a, b;
    while(cin >> a >> b)//while循环实现多次输入
    {
        cout << func(a, b) << endl;
    }
    return 0;
}