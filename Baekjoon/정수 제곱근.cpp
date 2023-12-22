#include <iostream>
#define rint register int
#define ll long long
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n;
	cin >> n;

	ll mid, start = 0, end = sqrt(n);
	while (start <= end) {
		mid = (start + end) / 2;
		if (mid < sqrt(n)) {
			start = mid + 1;
		} else {
			end = mid - 1;
		}
	}

	if (n > mid * mid) mid++;
	cout << mid << endl; 

	return 0;
}
