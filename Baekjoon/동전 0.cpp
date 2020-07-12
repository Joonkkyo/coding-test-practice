#include <iostream>

using namespace std;

int main(void)
{
	std::ios::sync_with_stdio(false);
	int N, K;
	int coins[11] = { 0, };
	int coin, max, idx;
	int cnt = 0;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> coins[i];
	}

	if (coins[N - 1] < K)
		idx = N - 1;
	for (int i = 0; i < N - 1; i++) {
		if (coins[i] <= K && K <= coins[i + 1]) {
			max = coins[i];
			idx = i;
		}
	}

	while (1) {
		K -= coins[idx];
		cnt++;
		if (K == 0)
			break;
		if (K < coins[idx]) {
			while (K < coins[idx])
				idx--;
		}
	}

	cout << cnt << '\n';
	return 0;
}