#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void) {
	int sheep_eat, goat_eat;  // a, b
	int total_num, total_eat;  // n, w
	int testCase;
	pair<int, int> ans;
	cin >> testCase;
	while (testCase--) {
		cin >> sheep_eat >> goat_eat >> total_num >> total_eat;

		int x, y;
		int cnt = 0;
		x = sheep_eat;
		y = goat_eat;

		for (int i = 1; i < total_num; i++) {
			if (i * x + (total_num - i) * y == total_eat) {
				ans = make_pair(i, total_num - i);
				cnt++;
			}
		}

		if (cnt == 0 || cnt >= 2)
			cout << -1 << endl;
		else
			cout << ans.first << " " << ans.second << endl;
	}
	return 0;
}