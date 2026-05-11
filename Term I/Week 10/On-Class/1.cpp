/* pointer (x,y)
   circle (x,y,r)
   cylinder(x,y,r,h)
*/
#include <iostream>
using namespace std;
class pointer 
{
    protected:
    double x,y;
}
class circle:public pointer
{
   protected:
   double r;

}
class cylinder:public circle
{
    protected:
    double h;

}


