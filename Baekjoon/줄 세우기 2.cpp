#include <iostream>
#include <queue>
#include <vector>
#define rint register int
using namespace std;

constexpr int MAX_N = 32001;
int indegree[MAX_N];
vector<int> graph[MAX_N];
int N, M;

void topologicalSort()
{
	queue<int> q;

	for (rint i = 1; i <= N; ++i)
	{
		if (indegree[i] == 0) q.push(i);
	}

	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		cout << now << ' ';
		for (rint i = 0; i < graph[now].size(); ++i)
		{
			int next = graph[now][i];
			indegree[next]--;
			if (indegree[next] == 0) q.push(next);
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int A, B;
	cin >> N >> M;
	while (M--)
	{
		cin >> A >> B;
		graph[A].push_back(B);
		indegree[B]++;
	}

	topologicalSort();

	return 0;
}
