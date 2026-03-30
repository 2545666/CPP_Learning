#include <iostream>
using namespace std;
int main ()
{
    int n;
    cin>>n;
    int a[1000];
    int max =1;
    int ans =1;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        if (a[i]==a[i-1])
        {
            max++;
            if (max>ans)
            ans=max;//记得存储最大长度
        }
        else
        max=1;
    }

    cout<<ans<<endl;
    return 0;

}