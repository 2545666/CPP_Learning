#include <iostream>
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
    Student(string id, double score)
    {
        this->id = id;
        this->score = score;
        total_score += score; 
        count++;
    }
    static double getAverage()
    {
        if(count==0)
      {
        return 0;
      }
      return total_score/count;
    }
};
double Student::total_score=0.0;
int Student::count=0;
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;++i)
    {
       string id;
        double score;
        cin >> id >> score;
        Student stu(id, score); 
    }
    cout << fixed << setprecision(2);
    cout << Student::getAverage() << endl;
    return 0;
}