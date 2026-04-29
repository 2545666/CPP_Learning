#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main() {
    int a[100];
    int count=0;
    for (int i=2;i<100;++i) {
        bool p=true;
        for (int j=2;j<=sqrt(i);++j) {
            if (i%j==0) {
                p=false;
                break;
            }
        }
        if (p==true) {
            a[count]=i;
            count ++;
        }
    }
    for (int i=0;i<count;++i) {
        cout<<setw(5)<<a[i];
        if ((i+1)%5==0)
        cout<<endl;
    }
    return 0;
}