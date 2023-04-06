#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

#define pp pair<string, int>
using namespace std;

bool cmp(const pp& a, const pp& b)
{
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	unordered_map<string, int> m;
	int K, L;
	cin >> K >> L;

	for (int i = 0; i < L; i++)
	{
		string student_num;
		cin >> student_num;
		if (m.find(student_num) != m.end())
			m.find(student_num)->second = i;
		else
			m[student_num] = i;
	}

	vector<pp> v(m.begin(), m.end());
	sort(v.begin(), v.end(), cmp);
	
	for (int i = 0; i < v.size(); i++)
	{
		if (i == K) break;
		cout << v[i].first << '\n';
	}
}
