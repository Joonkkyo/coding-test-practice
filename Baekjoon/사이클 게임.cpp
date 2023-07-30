#include <iostream>
#define rint register int
using namespace std;

constexpr int MAX_N = 500001;
int parent[MAX_N];

int find(int x)
{
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

bool merge(int x, int y)
{
	x = find(x);
	y = find(y);

	if (x == y) return true;
	else
	{
		if (x < y) parent[y] = x;
		else parent[x] = y;

		return false;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, u, v;
	int ans = 0;
	cin >> n >> m;
	for (rint i = 0; i < n; ++i) parent[i] = i;

	for (rint i = 1; i <= m; ++i)
	{
		cin >> u >> v;
		if (merge(u, v))
		{
			ans = i;
			break;
		}
	}

	if (ans == 0) cout << 0;
	else cout << ans;

	return 0;
}
