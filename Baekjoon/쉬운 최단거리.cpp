#include <iostream>
#include <queue>
#include <vector>
#define rint register int
#define pii pair<int, int>
using namespace std;

constexpr int MAX_N = 1001;

const int dy[4] = { 0, 1, 0, -1 };
const int dx[4] = { 1, 0, -1, 0 };
vector<int> board[MAX_N];

int dist[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];
int n, m;
int s_y, s_x;

void bfs() {
	queue<pii> q;
	q.push({ s_y, s_x });
	visited[s_y][s_x] = 1;

	while (!q.empty()) {
		int cur_y = q.front().first;
		int cur_x = q.front().second;
		q.pop();

		for (rint i = 0; i < 4; ++i) {
			int ny = cur_y + dy[i];
			int nx = cur_x + dx[i];
			if (0 <= ny && ny < n && 0 <= nx && nx < m && !visited[ny][nx]) {
				if (board[ny][nx] == 0) {
					dist[ny][nx] = 0;
					visited[ny][nx] = 1;
					continue;
				}

				dist[ny][nx] = dist[cur_y][cur_x] + 1;
				visited[ny][nx] = 1;
				q.push({ ny, nx });
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (rint i = 0; i < n; ++i) {
		for (rint j = 0; j < m; ++j) {
			dist[i][j] = 0;
			visited[i][j] = 0;
		}
	}

	for (rint i = 0; i < n; ++i) {
		for (rint j = 0; j < m; ++j) {
			int num;
			cin >> num;
			board[i].push_back(num);
		}
	}

	for (rint i = 0; i < n; ++i) {
		for (rint j = 0; j < m; ++j) {
			if (board[i][j] == 2) {
				s_y = i, s_x = j;
			}
		}
	}

	bfs();

	for (rint i = 0; i < n; ++i) {
		for (rint j = 0; j < m; ++j) {
			if (board[i][j] == 1 && dist[i][j] == 0) dist[i][j] = -1;
		}
	}

	for (rint i = 0; i < n; ++i) {
		for (rint j = 0; j < m; ++j) {
			cout << dist[i][j] << ' ';
		}
		cout << endl;
	}

	return 0;
}
