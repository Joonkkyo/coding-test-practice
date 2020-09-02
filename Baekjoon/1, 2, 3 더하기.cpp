#include <iostream>
using namespace std;

int dp[11] = { 0, };
int main(void)
{
	int testCase;
	int n;
	cin >> testCase;
	while (testCase--)
	{
		cin >> n;
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;

		if (n == 1)
			cout << dp[1] << endl;
		else if (n == 2)
			cout << dp[2] << endl;
		else if (n == 3)
			cout << dp[3] << endl;
		else
		{
			for (int i = 4; i <= n; i++)
				dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
			cout << dp[n] << endl;
		}
	}
	return 0;
}