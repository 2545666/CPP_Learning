#include <iostream>
#include <string>
using namespace std;
int main()
{
    string a;
    getline(cin,a);
    for(int i=0;i<a.size();++i)
    {
        if (a[i] >= 'A' && a[i] <= 'Z')
        {
            a[i]=a[i]+ 32;
        }
        else if(a[i]>='a'&&a[i]<='z')
        {
            a[i]=a[i]- 32;
        }
    }
    for(int i=0;i<a.size();++i)
    {
        cout<<a[i];
    }
    return 0;
}