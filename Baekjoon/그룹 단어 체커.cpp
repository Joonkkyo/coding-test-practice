#include <iostream>
using namespace std;

bool checked[26];
bool isGroup(string str);

int main(void)
{
	int testCase;
	int answer = 0;
	string str;
	cin >> testCase;

	while (testCase--)
	{
		cin >> str;
		if (isGroup(str))
			answer++;
	}
	cout << answer << endl;
	return 0;
}

bool isGroup(string str)
{
	fill_n(checked, 26, false);
	checked[str[0] - 'a'] = true;
	for (int i = 0; i < str.size() - 1; i++)
	{
		if (str[i] == str[i + 1])
			continue;
		else
		{
			if (checked[str[i + 1] - 'a'])
				return false;
			else
				checked[str[i + 1] - 'a'] = true;
		}
	}
	return true;
}