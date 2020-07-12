#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	int t;
	int sum = 0;
	int num1, num2;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> num1 >> num2;
		for (int n = num1; n <= num2; n++) {
			sum += n;
		}
		cout << sum << '\n';
		sum = 0;
	}
	return 0;
}