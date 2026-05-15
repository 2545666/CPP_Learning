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
        
    }
};