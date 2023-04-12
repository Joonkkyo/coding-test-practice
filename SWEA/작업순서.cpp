#include <iostream>
using namespace std;

constexpr int MAX = 1001;
int graph[MAX][MAX];
bool visited[MAX];
int V, E;

void init()
{
	memset(graph, 0, sizeof(graph));
	memset(visited, false, sizeof(visited));
}

void dfs(int v)
{
	if (visited[v])
		return;

	for (int i = 1; i <= V; i++)
		if (!visited[i] && graph[i][v] == 1) 
			return;
	
	visited[v] = true;
	cout << v << " ";

	for (int i = 1; i <= V; i++)
		if (!visited[i] && graph[v][i] == 1)
			dfs(i);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	for (int tc = 1; tc <= 10; tc++)
	{
		cin >> V >> E;

		init();

		for (int i = 0; i < E; i++)
		{
			int from, to;
			cin >> from >> to;
			graph[from][to] = 1;
		}

		cout << "#" << tc << " ";
		for (int i = 1; i <= V; i++)
		{
			if (!visited[i])
				dfs(i);
		}

		cout << '\n';
	}

	return 0;
}
