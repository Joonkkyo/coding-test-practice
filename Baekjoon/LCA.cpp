#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define rint register int
using namespace std;

constexpr int MAX_N = 50001;

vector<int> graph[MAX_N];
int parent[MAX_N];
int depth[MAX_N];
int visited[MAX_N];

int LCA(int a, int b)
{
	while (depth[a] != depth[b])
	{
		if (depth[a] > depth[b]) a = parent[a];
		else b = parent[b];
	}

	while (a != b)
	{
		a = parent[a];
		b = parent[b];
	}
	
	return a;
}

void dfs(int x, int d) // 노드 번호, 거리
{
	visited[x] = true;
	depth[x] = d;

	for (rint i = 0; i < graph[x].size(); ++i)
	{
		if (visited[graph[x][i]]) continue;
		parent[graph[x][i]] = x;
		dfs(graph[x][i], d + 1);
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt", "r", stdin);

	int N, a, b;
	cin >> N;
	for (rint i = 0; i < N - 1; ++i)
	{
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	dfs(1, 0);

	int M, m, n;
	cin >> M;
	while (M--)
	{
		cin >> m >> n;
		cout << LCA(m, n) << '\n';
	}
	
	return 0;
}
