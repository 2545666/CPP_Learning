#include <iostream>
using namespace std;
void set(int*& p)  
{
    p = new int;  //开辟新的堆
    *p = 100;
}

int main()
{
    int* p = nullptr;  
    set(p);

    if (p != nullptr)
    {
        cout << *p;
        delete p;     
    }
    else
    {
        cout << "P is NULL";
    }

    return 0;
}