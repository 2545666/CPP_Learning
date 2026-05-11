#include <iostream>
#include <cmath>
using namespace std;
int main()
{
int s;
cin>>s;
double t_bike,t_walk;
t_bike=t_walk=0;
t_bike= 27+23+s/3.0;
t_walk= s/1.2;
if (t_bike>t_walk)
{
    cout<<"Walk"<<endl;
}
else if (t_bike<t_walk)
{
    cout<<"Bike"<<endl;
}
else if (t_bike==t_walk)
{
    cout<<"All"<<endl;
}
 return 0;
} 