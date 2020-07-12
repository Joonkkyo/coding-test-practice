#include <iostream>
#include <algorithm>
#include <functional>
#include <cstring>

#define MAX 51
using namespace std;

int M, N, K;
int dy[] = { 1, -1, 0, 0 };  //상하좌우 검사
int dx[] = { 0, 0, -1, 1 };
int board[MAX][MAX] = { 0, };  //배추를 심을 곳
bool visited[MAX][MAX] = { 0, };  //방문 여부 검사

void dfs(int y, int x) {

	for (int i = 0; i < 4; i++) {
		int ax = x + dx[i];
		int ay = y + dy[i];

		if (ax < 0 || ay < 0 || ax >= M || ay >= N)  //배열 인덱스 넘으면 탈출
			continue;

		if (board[ay][ax] == 1 && !visited[ay][ax]) { //배추가 없거나, 방문했던 곳이면 탈출
			visited[ay][ax] = true;
			dfs(ay, ax);
		}
	}
}

int main(void) {
	std::ios::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		cin >> M >> N >> K;  //가로, 세로, 배추 갯수

		for (int i = 0; i < K; i++) {
			int x, y;
			cin >> x >> y;
			board[y][x] = 1;  //해당 좌표에 배추를 심는다.
		}

		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (board[i][j] == 1 && !visited[i][j]) {  //배추가 심어져있고, 처음 방문한 곳이면
					cnt++;  //배추흰지렁이를 놓는다.
					visited[i][j] = true;
					dfs(i, j);  //해당 지역과 연결된 부분 dfs탐색
				}
			}
		}
		cout << cnt << '\n';
		memset(board, 0, sizeof(board));  //배열 초기화
		memset(visited, 0, sizeof(visited));
	}
	return 0;
}