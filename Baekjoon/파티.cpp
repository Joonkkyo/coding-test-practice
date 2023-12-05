#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#define rint register int
#define pii pair<int, int>
using namespace std;

constexpr int MAX_N = 1001;
constexpr int INF = 1e9;

vector<pii> graph[2][MAX_N];
vector<int> dist[2];
int N, M, X;

void dijkstra(int flag) {
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	dist[flag][X] = 0;
	pq.push({ 0, X }); 

	while (!pq.empty()) {
		int now = pq.top().second;
		int cost = pq.top().first;
		pq.pop();

		if (dist[flag][now] < cost) continue;
		
		for (rint i = 0; i < graph[flag][now].size(); ++i) {
			int newCost = cost + graph[flag][now][i].second;
			int next = graph[flag][now][i].first;
			if (dist[flag][next] > newCost) {
				dist[flag][next] = newCost;
				pq.push({ newCost, next });
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt", "r", stdin);

	cin >> N >> M >> X;
	
	dist[0].resize(N + 1, INF);
	dist[1].resize(N + 1, INF);

	int start, end, cost;
	while (M--) {
		cin >> start >> end >> cost;
		graph[0][start].push_back({ end, cost });
		graph[1][end].push_back({ start, cost });
	}

	dijkstra(0); // 정방향
	dijkstra(1); // 역방향

	int maxDist = 0;
	for (rint i = 1; i <= N; ++i) {
		maxDist = max(maxDist, dist[0][i] + dist[1][i]);
	}

	cout << maxDist << '\n';

	return 0;
}
