#include <iostream>
#include <vector>
#include <queue>
using namespace std;

constexpr int MAX = 50001;
constexpr int INF = 1e9;

vector<pair<int, int> > graph[MAX]; //정방향
vector<pair<int, int> > reversed_graph[MAX]; //역방향

int dist1[MAX];
int dist2[MAX];

void dijkstra(int start, vector<pair<int, int> > graph[MAX], int* dist)
{
	priority_queue<pair<int, int> > pq;
	pq.push({ 0, start });
	dist[start] = 0;

	while (!pq.empty())
	{
		int d = -pq.top().first;
		int now = pq.top().second;
		pq.pop();
		
		if (dist[now] < d) continue;
		for (int i = 0; i < graph[now].size(); i++)
		{
			int cost = d + graph[now][i].second;
			if (cost < dist[graph[now][i].first])
			{
				dist[graph[now][i].first] = cost;
				pq.push({ -cost, graph[now][i].first });
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc)
	{
		int N, M, X, answer = 0;
		cin >> N >> M >> X;

		memset(graph, 0, sizeof(graph));
		memset(reversed_graph, 0, sizeof(reversed_graph));

		fill_n(dist1, MAX, INF);
		fill_n(dist2, MAX, INF);

		for (int i = 0; i < M; ++i)
		{
			int s, e, c;
			cin >> s >> e >> c;
			graph[s].push_back({ e, c });
			reversed_graph[e].push_back({ s, c });
		}

		dijkstra(X, graph, dist1);
		dijkstra(X, reversed_graph, dist2);

		for (int i = 1; i <= N; ++i)
		{
			if (dist1[i] == INF || dist2[i] == INF) continue;
			else answer = max(answer, dist1[i] + dist2[i]);
		}

		cout << "#" << tc << " " << answer << endl;
	}
}
