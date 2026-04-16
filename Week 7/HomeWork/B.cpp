#include <iostream>
#include <string>
using namespace std;
void input (string &id,string &name, int &s1,int &s2,int &s3)
{
  cin>>id>>name>>s1>>s2>>s3;
}
void print (string &id,string &name, int &s1,int &s2,int &s3)
{
    cout<<id<<","<<name<<","<<s1<<","<<s2<<","<<s3<<endl;
}
int main ()
{
    int N;
    cin>>N;
    string id[100];
    string name [100];
    
    int s1[100], s2[100], s3[100];
    for (int i=0;i<N;++i)
    {
       input(id[i],name[i],s1[i],s2[i],s3[i]);
    }
    for (int i=0;i<N;++i)
    {
       print(id[i],name[i],s1[i],s2[i],s3[i]);
    }
    return 0;
}