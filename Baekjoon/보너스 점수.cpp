#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void)
{
	int N;
	int bonus = 0;
	int answer = 0;
	string S;
	cin >> N;
	cin >> S;

	for (int i = 0; i < N; i++)
	{
		if (S[i] == 'X')
		{
			bonus = 0;
		}
		else if (S[i] == 'O')
		{
			answer += (i + 1) + bonus;
			bonus++;
		}
	}
	cout << answer << endl;
}