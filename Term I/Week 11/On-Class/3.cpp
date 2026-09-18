#include<iostream>
#include <cmath>
#include <iomanip>
using namespace std;
class Point
{
    private:
    int x;
    int y;
    public:
    Point(int px,int py)
    {
        x=px;
        y=py;
    }
    double distance (Point p)
    {
        int dx=p.x-x;
        int dy=p.y-y;
        double distance=sqrt(pow(dx,2)+pow(dy,2));
        return distance;
    }
};
int main ()
{
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    Point p1(x1,y1);
    Point p2(x2,y2);
    double distance=p1.distance (p2);
    cout<<fixed<<setprecision(2)<<distance<<endl;
    return 0;
}