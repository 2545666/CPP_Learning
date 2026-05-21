#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
class Point
{
    private:
    int x;
    int y;
    public:
    Point(int x,int y)
    {
        this->x=x;
        this->y=y;
    }
    double distance(Point p)
    {
        double d=sqrt(pow(this->x-p.x,2)+pow(this->y-p.y,2));
        return d;
    }
};
int main()
{
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    Point p1(x1,y1);
    Point p2(x2,y2);
    double res=p2.distance(p1);
    cout<<fixed<<setprecision(2)<<res<<endl;
    return 0;
}