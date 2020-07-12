#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool equalsWhenOneCharRemoved(string x, string y)
{
	int len_x = x.size();
	int len_y = y.size();

	string long_str, short_str;
	int long_len, short_len;
	int same_cnt = 0;

	int l_idx = 0;
	int s_idx = 0;

	if (len_x > len_y)
	{
		long_len = len_x, long_str = x;
		short_len = len_y, short_str = y;
	}
	else
	{
		long_len = len_y; long_str = y;
		short_len = len_x, short_str = x;
	}

	if (long_len - short_len != 1)  // �� ���ڿ� ª�� ������ ���̰� 1�� �ƴϸ� false
		return false;

	int loop = long_len;

	while (loop--)
	{
		if (long_str[l_idx] == short_str[s_idx]) // ��Ʈ���� ������ �ε��� ��� ����
		{
			same_cnt++;
			l_idx++, s_idx++;
		}

		else  // �ٸ��� ���̰� ª�� ��Ʈ���� �ε����� ����
			l_idx++;
	}

	if (same_cnt == short_len) // Ž���� ��ģ �� ��ġ�ϴ� ������ ������ ª�� ��Ʈ���� ���̿� ������ true
		return true;
	else
		return false;
}

int main(void)
{
	string s1, s2;
	cin >> s1 >> s2;
	bool result;
	result = equalsWhenOneCharRemoved(s1, s2);
	cout << result << endl;
}