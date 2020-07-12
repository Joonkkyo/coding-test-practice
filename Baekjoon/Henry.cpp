#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

int find_Deno(double fr, double a, double b);
int gcd(int n1, int n2);
double a, b;

int main(void) {
	std::ios::sync_with_stdio(false);
	int T;
	double a, b;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> a >> b;
		double val = a / b;
		int henry = find_Deno(val, a, b);
		cout << henry << endl;
	}
	return 0;
}

int find_Deno(double fr, double a, double b) {
	if (a == 1)
		return b;

	int sub_Deno = double(1 / fr) + 1;
	int temp1 = a * sub_Deno - b;
	int temp2 = b * sub_Deno;
	if (temp1 == 1)
		return temp2;
	int gcd_num = gcd(temp1, temp2);
	if (gcd_num != 1) {
		while ((temp1 % gcd_num == 0) && (temp2 % gcd_num == 0)) {
			temp1 /= gcd_num;
			temp2 /= gcd_num;
			if (temp1 == 1)
				return temp2;
		}
	}
	if (a * sub_Deno - b == 1)
		return sub_Deno * b;
	else {
		a = a * sub_Deno - b;
		b = sub_Deno * b;
		fr = fr - 1 / (double(sub_Deno));
		find_Deno(fr, a, b);
	}
}

int gcd(int n1, int n2) {  //최대공약수 구하기
	int r;
	do {
		r = n1 % n2;
		n1 = n2;
		n2 = r;
	} while (r != 0);

	return n1;
}