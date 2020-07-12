#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <map>
using namespace std;

int k;

void print_vector(vector<int>& v) {
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
}

void find_Case(vector<int>& v, vector<int>& r, map<int, int> m) {
	if (v.size() == 6) {
		print_vector(v);
		return;
	}

	int first = 0;
	if (!v.empty())
		first = m[v.back()];

	for (int i = first + 1; i <= k; i++) {
		v.push_back(r[i - 1]);
		find_Case(v, r, m);
		v.pop_back();
	}
}

int main(void) {
	int num;
	vector<int> Rotto;
	vector<int> temp;
	map<int, int> map;

	while (1) {
		cin >> k;
		if (k == 0)
			break;

		for (int i = 0; i < k; i++) {
			cin >> num;
			Rotto.push_back(num);
			map.insert(make_pair(Rotto[i], i + 1));
		}
		find_Case(temp, Rotto, map);
		cout << endl;

		Rotto.clear();
		temp.clear();
		map.clear();
	}
	return 0;
}
