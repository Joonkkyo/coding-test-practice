#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#define rint register int
#define pii pair<int, int>
using namespace std;

const int dy[4] = { 0, 0, -1, 1 };
const int dx[4] = { -1, 1, 0, 0 };
constexpr int MAX_N = 126;
constexpr int INF = 1e9;
int board[MAX_N][MAX_N];
int dist[MAX_N][MAX_N];
int N; 

void dijkstra() {
	priority_queue<pair<int, pii>> pq;
	pq.push({ -board[0][0], {0, 0}});
	dist[0][0] = board[0][0];

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int y = pq.top().second.first;
		int x = pq.top().second.second;
		pq.pop();

		if (dist[y][x] < cost) continue;
		for (rint i = 0; i < 4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (0 <= ny && ny < N && 0 <= nx && nx < N) {
				int newCost = cost + board[ny][nx];
				if (dist[ny][nx] > newCost) {
					dist[ny][nx] = newCost;
					pq.push({ -dist[ny][nx], {ny, nx} });
				}
			}
		}
	}
}

void input() {
	for (rint i = 0; i < N; ++i) {
		for (rint j = 0; j < N; ++j) {
			cin >> board[i][j];
		}
	}
}

void init() {
	for (rint i = 0; i < MAX_N; ++i) {
		for (rint j = 0; j < MAX_N; ++j) {
			dist[i][j] = INF;
		}
	}
}

void print() {
	for (rint i = 0; i < N; ++i) {
		for (rint j = 0; j < N; ++j) {
			cout << dist[i][j] << " ";
		}
		cout << endl;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt", "r", stdin);

	int qCnt = 1;
	while (true) {
		cin >> N;
		if (N == 0) break;
		init();
		input();
		dijkstra();
		//print();
		cout << "Problem " << qCnt++ << ": " << dist[N - 1][N - 1] << '\n';
	}

	return 0;
}
