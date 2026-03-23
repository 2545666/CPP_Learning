#include <iostream>
using namespace std;
int main (){
const int months=12;
int days[months]={31,28,31,30,31,30,31,31,30,31,30,31};
 for (int count =0;count<=months;count++)
{
    cout<<(count+1);
}
return 0;
}