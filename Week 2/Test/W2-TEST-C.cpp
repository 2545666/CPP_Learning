#include <iostream>
using namespace std;
int main() {
    int I;
    cin>>I;
    
    // 使用 double 确保计算精度
    double b = 0; 
    
    // 利用 if-else if 结构的短路特性，无需写闭区间如 (I > 100000 && I <= 200000)
    if (I <= 100000)
    {
        b = I * 0.1;
    } 
    
    else if (I <= 200000) 
    {
        b = 10000 + (I - 100000) * 0.075;
    } 
    
    else if (I <= 400000)
    {
        b = 17500 + (I - 200000) * 0.05;
    } 
    
    else if (I <= 600000) 
    {
        b = 27500 + (I - 400000) * 0.03;
    } 
    
    else if (I <= 1000000) 
    {
        b = 33500 + (I - 600000) * 0.015;
    } 
   
    else 
    {
        b = 39500 + (I - 1000000) * 0.01;
    }
   
    // 强制类型转换为 int，实现向下取整并输出
    cout << (int)b << endl;
    
    return 0;
}
