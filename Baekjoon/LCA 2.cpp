#include <iostream>
#include <vector>
#define rint register int
#define swap(a, b) { a ^= b ^= a ^= b; }

using namespace std;

constexpr int MAX_N = 100001;
constexpr int LOG = 18;

vector<int> graph[MAX_N];
int N;
int parent[MAX_N][LOG];
int depth[MAX_N];
int visited[MAX_N];

int LCA(int a, int b)
{
	if (depth[a] > depth[b]) swap(a, b); // b가 더 깊게
	for (rint i = LOG - 1; i >= 0; --i)
		if (depth[b] - depth[a] >= (1 << i)) b = parent[b][i];

	if (a == b) return a;

	for (rint i = LOG - 1; i >= 0; --i)
	{
		if (parent[a][i] != parent[b][i])
		{
			a = parent[a][i];
			b = parent[b][i];
		}
	}
	
	return parent[a][0];
}

void dfs(int x, int d) // 노드 번호, 거리
{
	visited[x] = true;
	depth[x] = d;

	for (rint i = 0; i < graph[x].size(); ++i)
	{
		if (visited[graph[x][i]]) continue;
		parent[graph[x][i]][0] = x;
		dfs(graph[x][i], d + 1);
	}
}

void set_parent()
{
	dfs(1, 0);
	for (rint i = 1; i < LOG; ++i)
		for (rint j = 1; j <= N; ++j)
			parent[j][i] = parent[parent[j][i - 1]][i - 1];
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b;
	cin >> N;
	for (rint i = 0; i < N - 1; ++i)
	{
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	set_parent();

	int M, m, n;
	cin >> M;
	while (M--)
	{
		cin >> m >> n;
		cout << LCA(m, n) << '\n';
	}
	
	return 0;
}
