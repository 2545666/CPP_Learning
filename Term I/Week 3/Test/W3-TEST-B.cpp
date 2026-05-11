#include <iostream>
using namespace std;

int main() 
{
    int n, m;
    cin>>n>>m;
    int count=0;
    int num;
    for (int i=0; i<n; ++i)
    {
        cin>>num;
        if (num==m)
        count++;
    }
    cout<< count<<endl;
    return 0;
}