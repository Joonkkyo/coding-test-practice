#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <functional>
using namespace std;

int main(void) {
	char board[501];
	vector<int> sum;
	int size;
	int X_cnt = 0;
	int errCnt = 0;
	int cnt = 0;
	int finish = 0;
	cin >> board;
	size = strlen(board);

	for (int i = 0; i < size; i++) {
		if (board[i] == 'X')
			cnt++;
	}

	if (cnt == 0) {
		finish++;
		for (int i = 0; i < size; i++)
			cout << board[i];
		cout << endl;
	}

	if (finish == 0) {
		for (int i = 0; i < size; i++) {
			if (board[i] == 'X')
				X_cnt++;
			if (board[i] == '.' || i == size - 1) { //. 또는 배열의 끝일 때, 그 부분까지 X 갯수를 저장
				sum.push_back(X_cnt);
				if (board[i] == '.')
					X_cnt = 0;
			}
		}
		sort(sum.begin(), sum.end(), greater<int>());  //내림차순으로 정렬했을 때, 첫번째 배열 값이 0이면 X가 없는 것이므로 예외처리
		
		if (sum[0] == 0)
			errCnt = 1;

		for (int i = 0; i < sum.size(); i++) {  //X의 갯수의 합중에 2의 배수가 아닌 것이 있으면 예외처리
			if (sum[i] % 2 != 0) {
				errCnt = 1;
				break;
			}
		}

		X_cnt = 0;

		for (int i = 0; i < size; i++) {
			if (errCnt == 1) {
				cout << -1;
				break;
			}

			if (board[i] == 'X')
				X_cnt++;

			if (X_cnt == 2 && (board[i + 1] == '.' || i == size - 1)) {
				cout << "BB";
				X_cnt = 0;
			}

			if (board[i] == '.') {
				cout << ".";
				X_cnt = 0;
			}

			if (X_cnt == 4) {
				cout << "AAAA";
				X_cnt = 0;
			}
		}
		cout << '\n';
	}

	return 0;
}
