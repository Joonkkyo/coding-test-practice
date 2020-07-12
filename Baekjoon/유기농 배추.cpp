#include <iostream>
#include <algorithm>
#include <functional>
#include <cstring>

#define MAX 51
using namespace std;

int M, N, K;
int dy[] = { 1, -1, 0, 0 };  //�����¿� �˻�
int dx[] = { 0, 0, -1, 1 };
int board[MAX][MAX] = { 0, };  //���߸� ���� ��
bool visited[MAX][MAX] = { 0, };  //�湮 ���� �˻�

void dfs(int y, int x) {

	for (int i = 0; i < 4; i++) {
		int ax = x + dx[i];
		int ay = y + dy[i];

		if (ax < 0 || ay < 0 || ax >= M || ay >= N)  //�迭 �ε��� ������ Ż��
			continue;

		if (board[ay][ax] == 1 && !visited[ay][ax]) { //���߰� ���ų�, �湮�ߴ� ���̸� Ż��
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
		cin >> M >> N >> K;  //����, ����, ���� ����

		for (int i = 0; i < K; i++) {
			int x, y;
			cin >> x >> y;
			board[y][x] = 1;  //�ش� ��ǥ�� ���߸� �ɴ´�.
		}

		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (board[i][j] == 1 && !visited[i][j]) {  //���߰� �ɾ����ְ�, ó�� �湮�� ���̸�
					cnt++;  //�����������̸� ���´�.
					visited[i][j] = true;
					dfs(i, j);  //�ش� ������ ����� �κ� dfsŽ��
				}
			}
		}
		cout << cnt << '\n';
		memset(board, 0, sizeof(board));  //�迭 �ʱ�ȭ
		memset(visited, 0, sizeof(visited));
	}
	return 0;
}