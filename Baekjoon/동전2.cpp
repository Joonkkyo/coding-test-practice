#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	int d[10001]; //d[i] : i원을 만들기 위한 최소 갯수
	int n, k;
	int INF = 100001;
	vector<int> coin;

	cin >> n >> k;
	coin.resize(n, 0);

	for (int i = 0; i < n; i++)
		cin >> coin[i];

	for (int i = 1; i <= k; i++) {
		d[0] = 0;
		d[i] = INF;
		for (int j = 0; j < n; j++) {
			if (i >= coin[j]) {
				d[i] = min(d[i - coin[j]] + 1, d[i]);
			}
		}
	}
	if (d[k] == INF)
		cout << -1 << '\n';
	else
		cout << d[k] << '\n';

	return 0;
}