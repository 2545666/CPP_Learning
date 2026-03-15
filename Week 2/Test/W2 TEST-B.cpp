#include <iostream>
#include<iomanip>
using namespace std;
int main()
{
    float f;
    cin>>f;
    float c=5.0*(f-32)/9.0;
    cout<<fixed<<setprecision(2)<<c<<endl;
    return 0;
}
