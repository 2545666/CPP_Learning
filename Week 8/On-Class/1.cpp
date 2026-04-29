#include <iostream>
#include <iomanip>
using namespace std;
int main ()
{
    float height;
    cin>>height;
    cout<<"Hedy,you are "<<fixed<<setprecision(3)<<height<<" feet tall."<<endl;
    return 0;
}