#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#define rint register int
#define pii pair<int, int>
using namespace std;

const int dy[4] = { 0, 0, -1, 1 };
const int dx[4] = { -1, 1, 0, 0 };
constexpr int MAX_N = 1001;
constexpr int INF = 1e9;

vector<pii> graph[MAX_N];
int dist[MAX_N];
int route[MAX_N];
vector<int> routes;
int s, e;

priority_queue<pii, vector<pii>, greater<pii>> pq;
void dijkstra() {
	pq.push({ 0, s });
	dist[s] = 0;

	while (!pq.empty()) {
		int cost = pq.top().first;
		int now = pq.top().second;
		pq.pop();
		if (dist[now] < cost) continue;
		
		for (rint i = 0; i < graph[now].size(); ++i) {
			int newCost = cost + graph[now][i].second;
			int next = graph[now][i].first;
			if (dist[next] > newCost) {
				route[next] = now;
				dist[next] = newCost;
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

	int n, m;
	int u, v, c;
	cin >> n >> m;

	for (rint i = 1; i <= n; ++i) {
		dist[i] = INF;
	}

	while (m--) {
		cin >> u >> v >> c;
		graph[u].push_back({ v, c });
	}

	cin >> s >> e;
	dijkstra();
	cout << dist[e] << '\n';

	int end = e;
	while (end) {
		routes.push_back(end);
		end = route[end];
	}

	cout << routes.size() << '\n';
	for (rint i = routes.size() - 1; i >= 0; --i) cout << routes[i] << ' ';
	cout << '\n';

	return 0;
}
