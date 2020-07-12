#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>
using namespace std;

const int dy[] = { 0, 0, -1, 1 };
const int dx[] = { 1, -1, 0, 0 };
vector<string> board;
int T, M, N;
int room_cnt;

void dfs(int y, int x) {
	board[y][x] = '+';
	room_cnt++;
	for (int m = 0; m < 4; m++) {
		int next_y = y + dy[m];
		int next_x = x + dx[m];
		if (next_y >= 0 && next_y < N
			&& next_x >= 0 && next_x < M
			&& board[next_y][next_x] == '.') {
			dfs(next_y, next_x);
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> M >> N;  //가로, 세로
		for (int i = 0; i < N; i++) {
			string s;
			cin >> s;
			board.push_back(s);
		}
		vector<int> ret;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				room_cnt = 0;
				if (board[i][j] == '.') {
					dfs(i, j);
					ret.push_back(room_cnt);
				}
			}
		}
		sort(ret.begin(), ret.end(), greater<int>());
		cout << ret.size() << endl;
		for (int i = 0; i < ret.size(); i++) {
			cout << ret[i] << " ";
		}
		cout << endl;
		board.clear();
		ret.clear();
	}
	return 0;
}