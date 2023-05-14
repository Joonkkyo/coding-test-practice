#include <iostream>
#include <vector>
#define rint register int
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K, temp;
	cin >> N >> K;
	vector<int> arr(N + 1);
	vector<int> prefix_sum(N + 1, 0);
	for (rint i = 1; i <= N; ++i)
	{
		cin >> temp;
		prefix_sum[i] = prefix_sum[i - 1] + temp;
	}
	
	int ans = -10000000;
	for (int i = K; i <= N; ++i) 
		ans = max(ans, prefix_sum[i] - prefix_sum[i - K]);

	cout << ans << '\n';
	return 0;
}
