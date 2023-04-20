#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

constexpr int MAX = 50001;
int parent[MAX];

int find(int x)
{
	if (parent[x] == x) return x;
	else parent[x] = find(parent[x]);
}

void merge(int x, int y)
{
	x = find(x);
	y = find(y);

	if (x < y) parent[y] = x;
	else parent[x] = y;
}

int main(void)
{
	ios::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.tie(NULL);
	memset(parent, 0, sizeof(parent));

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc)
	{
		int N, M, answer = 0;
		cin >> N >> M;

		for (int i = 1; i <= N; ++i)
			parent[i] = i;

		vector<pair<int, pair<int, int>>> edges;
		for (int i = 0; i < M; ++i)
		{
			int s, e, c;
			cin >> s >> e >> c;
			edges.push_back({ c, {s, e} });
		}
		
		sort(edges.begin(), edges.end());
		for (int i = 0; i < M; ++i)
		{
			int cost = edges[i].first;
			int u = edges[i].second.first, v = edges[i].second.second;

			if (find(u) != find(v))
			{
				merge(u, v);
				answer += cost;
			}
		}

		cout << "#" << tc << " " << answer << endl;
	}
}
