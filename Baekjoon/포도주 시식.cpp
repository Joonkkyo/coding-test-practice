#include <iostream>
#include <algorithm>
using namespace std;

int glass[10001];
int dp[10001];
int main(void)
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> glass[i];

	dp[1] = glass[1];

	if (n == 1)
	{
		cout << dp[1] << endl;
		return 0;
	}

	dp[2] = glass[1] + glass[2];

	if (n == 2)
	{
		cout << dp[2] << endl;
		return 0;
	}

	for (int i = 3; i <= n; i++)
	{
		dp[i] = max(dp[i - 1], max(dp[i - 2] + glass[i], dp[i - 3] + glass[i - 1] + glass[i]));
	}

	cout << dp[n] << endl;
	return 0;
}