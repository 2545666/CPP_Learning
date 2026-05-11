#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char s[501];
    int i = 0;
    char c;
    while (cin.get(c) && c != '\n' && i < 500) {
        s[i++] = c;
    }
    s[i] = '\0'; 
    char *p = s;
    char *start = s;

    while (*p != '\0') {
        while (*p != ' ' && *p != '\0') {
            p++;
        }

        // 双指针反转单词
        char *left = start;
        char *right = p - 1;
        while (left < right) {
            char temp = *left;
            *left = *right;
            *right = temp;
            left++;
            right--;
        }
        if (*p == ' ') {
            p++;
            start = p;
        }
    }
    cout << s << endl;
    return 0;
}