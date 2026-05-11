#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int num;
	cin >> num;
	int len = floor(log10(num)) + 1;
	cout << len << endl;
	int digits[5];
	int temp = num;
	for (int i = len - 1; i >= 0; i--) 
	{
		digits[i] = temp % 10;
		temp /= 10;
	}
	for (int i = 0; i < len; i++) {
		cout << digits[i];
		if (i != len - 1) {
			cout << " ";
		}
	}
	cout << endl;
	for (int i = len - 1; i >= 0; i--) {
		cout << digits[i];
	}
	cout << endl;
	return 0;
}