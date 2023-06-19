#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <string>
#define rint register int
#define pii pair<int, int>
using namespace std;

constexpr int MAX_N = 101;
constexpr int MAX_M = 101;
constexpr int MAX_INT = 999999;

int board[MAX_N][MAX_M], dist[MAX_N][MAX_M];
const int dy[4] = { 0, 0, 1, -1 };
const int dx[4] = { 1, -1, 0, 0 };
int M, N; // 가로, 세로

void bfs()
{
	queue<pii> q;
	q.emplace(0, 0);
	dist[0][0] = 0;

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (rint i = 0; i < 4; ++i)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;

			if (board[ny][nx] == 0)
			{
				if (dist[ny][nx] > dist[y][x])
				{
					dist[ny][nx] = dist[y][x];
					q.emplace(ny, nx);
				}
			}

			if (board[ny][nx] == 1)
			{
				if (dist[ny][nx] > dist[y][x] + 1)
				{
					dist[ny][nx] = dist[y][x] + 1;
					q.emplace(ny, nx);
				}
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt", "r", stdin);

	cin >> M >> N;
	string str;
	for (rint i = 0; i < N; ++i)
	{
		cin >> str;
		for (rint j = 0; j < M; ++j)
		{
			board[i][j] = str[j] - '0';
			dist[i][j] = MAX_INT;
		}
	}

	bfs();
	cout << dist[N - 1][M - 1] << '\n';

	return 0;
}
