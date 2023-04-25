#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

constexpr int MAX = 50001;
vector<int> graph[MAX];
int indegree[MAX];

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
		memset(graph, 0, sizeof(graph));
		memset(indegree, 0, sizeof(indegree));

		int N, M;
		cin >> N >> M;
		while (M--)
		{
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			indegree[b]++;
		}
		
		deque<int> dq;
		vector<int> result;

		for (register int i = 1; i <= N; ++i)
			if (indegree[i] == 0) dq.push_back(i);

		while (!dq.empty())
		{
			int now = dq.front();
			dq.pop_front();
			result.push_back(now);

			for (register int i = 0; i < graph[now].size(); ++i)
			{
				indegree[graph[now][i]]--;
				if (indegree[graph[now][i]] == 0)
					dq.push_back(graph[now][i]);
			}
		}

		cout << "#" << tc << " ";
		for (int num : result)
			cout << num << " ";
		cout << '\n';
	}

	return 0;
}
