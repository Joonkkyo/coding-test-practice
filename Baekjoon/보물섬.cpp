#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

constexpr int MAX = 51;
char board[MAX][MAX];
int visited[MAX][MAX];
int dist[MAX][MAX];

const int dy[4] = { -1, 0, 1, 0 };
const int dx[4] = { 0, -1, 0, 1 };
int R, C, max_dist;

struct Point {
	int y;
	int x;
};

int dfs(int i, int j)
{
	queue<Point> q;
	Point p = { i, j };
	max_dist = 0;
	dist[i][j] = 0;
	visited[i][j] = 1;
	q.push(p);

	while (!q.empty())
	{
		int y = q.front().y;
		int x = q.front().x;
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (0 <= ny && ny < R && 0 <= nx && nx < C && board[ny][nx] == 'L' && !visited[ny][nx])
			{
				dist[ny][nx] = dist[y][x] + 1;
				visited[ny][nx] = 1;
				p.y = ny;
				p.x = nx;
				q.push(p);

				max_dist = max(max_dist, dist[ny][nx]) ;
			}
		}
	}

	return max_dist;
}

void init()
{
	max_dist = 0;
	memset(dist, -1, sizeof(dist));
	memset(visited, 0, sizeof(visited));
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	init();
	cin >> R >> C;

	for (int i = 0; i < R; ++i)
		for (int j = 0; j < C; ++j)
			cin >> board[i][j];

	int temp, answer = 0;
	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			if (board[i][j] == 'L') answer = max(answer, dfs(i, j));
			init();
		}
	}

	cout << answer << endl;
	return 0;
}
