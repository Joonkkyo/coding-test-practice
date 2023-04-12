#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

const vector<string> targets = { "ZRO", "ONE", "TWO", "THR", "FOR", "FIV", "SIX", "SVN", "EGT", "NIN" };

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test_case;
	cin >> test_case;

	for (int tc = 1; tc <= test_case; tc++)
	{
		string tc_num;
		int size; 
		cin >> tc_num >> size;

		vector<string> str_v(size);
		vector<int> num_v(size);
		unordered_map<string, int> word_to_num;
		unordered_map<int, string> num_to_word;

		for (register int i = 0; i < size; i++)
			cin >> str_v[i];

		for (register int i = 0; i < targets.size(); i++)
		{
			word_to_num[targets[i]] = i;
			num_to_word[i] = targets[i];
		}

		for (register int i = 0; i < size; i++)
			num_v[i] = word_to_num[str_v[i]];

		sort(num_v.begin(), num_v.end());

		for (register int i = 0; i < size; i++)
			str_v[i] = num_to_word[num_v[i]];

		cout << tc_num << '\n';
		for (string s : str_v)
			cout << s << " ";
		cout << '\n';
	}

	return 0;
}
