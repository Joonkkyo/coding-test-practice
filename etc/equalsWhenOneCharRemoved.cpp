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

	if (long_len - short_len != 1)  // 긴 문자와 짧은 문자의 차이가 1이 아니면 false
		return false;

	int loop = long_len;

	while (loop--)
	{
		if (long_str[l_idx] == short_str[s_idx]) // 스트링이 같으면 인덱스 모두 증가
		{
			same_cnt++;
			l_idx++, s_idx++;
		}

		else  // 다르면 길이가 짧은 스트링의 인덱스만 증가
			l_idx++;
	}

	if (same_cnt == short_len) // 탐색을 마친 후 일치하는 문자의 개수가 짧은 스트링의 길이와 같으면 true
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