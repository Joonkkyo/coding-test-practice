#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

constexpr int MAX = 11;
int graph[MAX][MAX];
bool visited[MAX];
int V, answer;

void dfs(int v, int depth)
{
	if (depth > answer)
		answer = depth;

	for (int i = 1; i <= V; i++)
	{
		if (!visited[i] && graph[v][i] == 1)
		{
			visited[i] = true;
			dfs(i, depth + 1);
			visited[i] = false;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	int N;
	cin >> V >> N;
	memset(graph, 0, sizeof(graph));
	memset(visited, false, sizeof(visited));

	answer = 0;
	for (int i = 0; i < N; i++)
	{
		int size;
		cin >> size;
		int* temp = new int[size];
		for (int j = 0; j < size; j++)
			cin >> temp[j];

		for (int i = 0; i < size - 1; i++)
		{
			int from = temp[i];
			int to = temp[i + 1]; 
			graph[from][to] = 1;
		}
    
    delete[] temp;
	}

	for (int i = 1; i <= V; i++)
	{
		visited[i] = true;
		dfs(i, 1);
		visited[i] = false;
	}

	cout << answer << endl;
}
