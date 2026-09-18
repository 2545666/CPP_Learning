#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string s, k[] = {"auto","break","case","char","const","continue","default","do","double","else","enum","extern","float","for","goto","if","int","long","register","return","short","signed","sizeof","static","struct","switch","typedef","union","unsigned","void","volatile","while"};
    int i, f = 1;
    cin >> s;
    for (i = 0; i < 32; i++) 
    {
        if (s == k[i])
        f = 0; 
        if (f && isdigit(s[0]))
        f = 0;
    }

    for (i = 0; f && i < s.size(); i++) 
    {
        if (!isalnum(s[i]) && s[i] != '_') f = 0;
    }
    
    cout << (f ? "yes" : "no") << endl;
    return 0;
}