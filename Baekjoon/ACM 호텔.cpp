#include <iostream>
#include <algorithm>
using namespace std;

int find_Count(int order, int height);

int main(void) {
	int T, H, W, order, cnt, num;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> H >> W >> order;
		cnt = find_Count(order, H);
		num = order % H;

		if (num == 0) {
			num = H;
			cnt--;
		}
		cout << num * 100 + cnt + 1 << '\n';
	}
}

int find_Count(int order, int height) {
	int count = order / height;
	return count;
}
