#include <iostream>

using namespace std;

int main(void)
{
	std::ios::sync_with_stdio(false);
	int taken_money, change;
	int cnt = 0;
	int idx, max;
	const int coin[6] = { 1, 5, 10, 50, 100, 500 };

	cin >> taken_money;
	change = 1000 - taken_money;
	if (coin[5] < change)
		idx = 5;

	for (int i = 0; i < 6; i++) {
		if (coin[i] <= change && change <= coin[i + 1]) {
			max = coin[i];
			idx = i;
		}
	}

	while (1) {
		change -= coin[idx];
		cnt++;
		if (change == 0)
			break;
		if (change < coin[idx]) {
			while (change < coin[idx])
				idx--;
		}
	}
	cout << cnt << '\n';
	return 0;
}