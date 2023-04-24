#include <iostream>
using namespace std;

constexpr int MAX = 1001;
int map[MAX][MAX];
int dp[MAX][MAX];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc)
	{
		int N;
		cin >> N;
		for (register int i = 1; i <= N; ++i)
		{
			string s;
			cin >> s;
			for (register int j = 1; j <= N; ++j)
			{
				map[i][j] = s[j - 1] - '0';
				if (map[i][j] == 0) map[i][j] = 1;
				else map[i][j] = 0;
			}
		}

		int answer = 0;
		for (register int i = 1; i <= N; ++i)
		{
			for (register int j = 1; j <= N; ++j)
			{
				if (map[i][j] == 1)
				{
					dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
					answer = max(answer, dp[i][j]);
				}
			}
		}

		cout << "#" << tc << " " << answer << endl;
	}

	return 0;
}
