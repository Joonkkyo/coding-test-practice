#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;

typedef struct info {
	int start;
	int end;
	int cost;
} info;

int dp[501];

bool cmp(const info& a, const info& b)
{
	return a.end < b.end; 
}

int main(void)
{
	ios::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt", "r", stdin);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc)
	{
		memset(dp, 0, sizeof(dp));
		int N, M;
		cin >> N >> M;
		vector<info> v(N);
		for (int i = 0; i < N; ++i)
		{
			int s, e, c; 
			cin >> v[i].start >> v[i].end >> v[i].cost;
		}
		sort(v.begin(), v.end(), cmp);
		
		dp[0] = v[0].cost;
		for (int i = 1; i < N; ++i)
		{
			int cost = 0, idx = -1;
			for (int j = 0; j < i; ++j)
			{
				if (v[j].end >= v[i].start) break;
				idx = j;
			}
			
			if (idx >= 0) cost = dp[idx];
			dp[i] = max(dp[i - 1], v[i].cost + cost);
		}

		cout << "#" << tc << " " << dp[N - 1] << endl;
	}
}
