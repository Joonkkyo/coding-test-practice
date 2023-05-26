#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define rint register int
using namespace std;

constexpr int MAX = 1001;
int dp[MAX][MAX];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	
	int T, r, c;
	cin >> T;
	string str1, str2;
	for (rint tc = 1; tc <= T; ++tc)
	{
		cin >> str1 >> str2;
		r = str1.length();
		c = str2.length();

		for (rint i = 1; i <= r; ++i)
		{
			for (rint j = 1; j <= c; ++j)
			{
				if (str1[i - 1] == str2[j - 1])
					dp[i][j] = dp[i - 1][j - 1] + 1;
				else
					dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		}

		cout << "#" << tc << " " << dp[r][c] << endl;
	}


	return 0;
}
