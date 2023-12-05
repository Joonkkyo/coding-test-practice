#include <iostream>
#include <vector>
#include <queue>
#define rint register int
using namespace std;

constexpr int MAX_V = 401;
constexpr int INF = 1e9;
int dist[MAX_V][MAX_V];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt", "r", stdin);

	int V, E;
	cin >> V >> E;

	for (rint i = 1; i <= V; ++i) {
		for (rint j = 1; j <= V; ++j) {
			dist[i][j] = INF;
		}
	}

	int start, end, cost;
	for (rint i = 0; i < E; ++i) {
		cin >> start >> end >> cost;
		dist[start][end] = cost;
	}

	for (rint k = 1; k <= V; ++k) {
		for (rint i = 1; i <= V; ++i) {
			for (rint j = 1; j <= V; ++j)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
		}
	}

	int minDist = INF;
	for (rint i = 1; i <= V; ++i) {
		if (dist[i][i] != INF) minDist = min(minDist, dist[i][i]);
	}

	int result = (minDist == INF) ? -1 : minDist;
	cout << result << '\n';

	return 0;
}
