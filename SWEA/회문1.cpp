#include <iostream>
#include <cstring>
using namespace std;

constexpr int MAX = 8;
char board[MAX][MAX]; 

bool isPalindrome(string s)
{
	int size = s.size();
	for (register int i = 0; i < size / 2; i++)
	{
		if (s[i] != s[size - 1 - i])
			return false;
	}

	return true;
}

int calRowPalindrome(int len)
{
	int count = 0;
	for (register int i = 0; i < MAX; i++)
	{
		for (register int j = 0; j <= MAX - len; j++)
		{
			string temp = "";
			
			for (register int k = j; k < len + j; k++)
				temp += board[i][k];

			if (isPalindrome(temp))
				count++;
		}
	}

	return count;
}

int calColPalindrome(int len)
{
	int count = 0;
	for (register int i = 0; i < MAX; i++)
	{
		for (register int j = 0; j <= MAX - len; j++)
		{
			string temp = "";

			for (register int k = j; k < len + j; k++)
				temp += board[k][i];

			if (isPalindrome(temp))
				count++;
		}
	}

	return count;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int tc = 1; tc <= 10; tc++)
	{
		int length;
		cin >> length;

		for (register int i = 0; i < MAX; i++)
		{
			string str;
			cin >> str;
			for (register int j = 0; j < MAX; j++)
				board[i][j] = str[j];
		}

		cout << "#" << tc << " " << calRowPalindrome(length) + calColPalindrome(length) << '\n';
	}

	return 0;
}
