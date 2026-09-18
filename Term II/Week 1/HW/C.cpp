#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Student
{
private:
    string id;
    double score;
    static double total_score;
    static int count;
public:
    Student(string id_, double s_)
    {
        id = id_;
        score = s_;
        total_score += s_;
        count++;
    }
    static double getAverage()
    {
        if(count == 0)
            return 0;
        return total_score / count;
    }
};
//静态成员类外初始化
double Student::total_score = 0;
int Student::count = 0;

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string sid;
        double sc;
        cin >> sid >> sc;
        Student s(sid, sc);
    }
    cout << fixed << setprecision(2) << Student::getAverage() << endl;
    return 0;
}
