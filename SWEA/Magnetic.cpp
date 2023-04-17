#include <iostream>
using namespace std;

constexpr int MAX = 100;
int board[MAX][MAX];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int tc = 1; tc <= 10; tc++)
	{
		int size;
		cin >> size;
		memset(board, 0, sizeof(board));
		
		for (register int i = 0; i < MAX; i++)
			for (register int j = 0; j < MAX; j++)
				cin >> board[i][j];

		int answer = 0;
		for (register int i = 0; i < MAX; i++)
		{
			bool flag = false;
			for (register int j = 0; j < MAX; j++)
			{
				if (board[j][i] == 1) flag = true;
				else
				{
					if (board[j][i] == 2 && flag)
					{
						answer++;
						flag = false;
					}
				}
			}
		}
    
		cout << "#" << tc << " " << answer << '\n';
	}
	
	return 0;
}
