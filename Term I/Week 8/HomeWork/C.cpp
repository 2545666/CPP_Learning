#include <iostream>
#include <string>
#include <unordered_map>//哈希映射表，用于存字母对应关系
using namespace std;

int main() {
    string a, b, t;//a：对照表密文，b：对照表明文，t：要解密的内容
    cin >> a >> b >> t;

    unordered_map<char, char> m, n;//两个哈希表，m = 密文 → 明文（解密用），n = 明文 → 密文（防冲突用）
    bool ok = 1;
//开始遍历
    for (int i = 0; i<a.size(); i++) {
        char x = a[i], y = b[i];//取出第i个 密文x、明文y
        m[x]=y; //存：密文x → 明文y
        n[y]=x; //存：明文y → 密文x
        //如果x已经存过，且对应的值不是y → 冲突=不合法
        if (m.count(x) && m[x]!=y) 
        ok=0;
        //如果y已经存过，且对应的值不是x → 冲突=不合法
        if (n.count(y) && n[y]!=x) 
        ok=0;
    }

    if (m.size()!=26) //26个字母均要映射
    ok=0; 

    if (!ok) 
    cout << "Failed\n";
    else {
        string s;
        //逐个解密要翻译的内容
        for (char ch:t) s+=m[ch];
        cout << s << endl;
    }
    return 0;
}