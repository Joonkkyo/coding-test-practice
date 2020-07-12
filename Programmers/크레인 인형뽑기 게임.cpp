#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	stack<int> basket;
	int answer = 0;
	int m_size = moves.size();
	int temp = 0;
	int flag = 0;
	for (int i = 0; i < m_size; i++)
	{
		if (!basket.empty())
			temp = basket.top();

		for (int j = 0; j < board.size(); j++)
		{
			if (board[board.size() - 1][moves[i] - 1] == 0)  // 인형이 해당 칸에 없으면
			{
				flag = 1;
				break;
			}
			if (board[j][moves[i] - 1] != 0)  // 인형을 만난 경우
			{
				basket.push(board[j][moves[i] - 1]);
				board[j][moves[i] - 1] = 0;
				break;
			}
		}
		if (basket.size() > 1 && !flag)
		{
			if (basket.top() == temp)
			{
				answer += 2;
				basket.pop();
				basket.pop();
			}
		}
	}
	return answer;
}

int main(void)
{
	vector<vector<int>> board = { {0, 0, 0, 0, 0}, {0, 0, 1, 0, 3}, {0, 2, 5, 0, 1}, {4, 2, 4, 4, 2}, {3, 5, 1, 3, 1} };
	vector<int> moves = { 1, 5, 3, 5, 1, 2, 1, 4 };

	cout << solution(board, moves);
}