#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <map>
using namespace std;

void print_vector(vector<int>& v) {
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << "\n";
}

void find_Seven_Dwarf(vector<int>& v, vector<int>& h, map<int, int>& m) {
	if (v.size() == 7) {
		int sum = 0;
		for (int i = 0; i < v.size(); i++) {
			sum += v[i];
		}

		if (sum == 100) {  //뽑은 7명의 난쟁이의 키의 합이 100이면 출력
			print_vector(v);
			return;
		}
	}
	int first = 0;
	if (!v.empty())
		first = m[v.back()];

	for (int i = first + 1; i <= 9; i++) {
		v.push_back(h[i - 1]);
		find_Seven_Dwarf(v, h, m);
		v.pop_back();
	}
}

int main(void) {
	int height;
	map<int, int> m;
	vector<int> temp;
	vector<int> h;

	for (int i = 0; i < 9; i++) {
		cin >> height;
		h.push_back(height);
	}

	sort(h.begin(), h.end());  //입력된 9명의 난쟁이의 키를 오름차순으로 정렬

	for (int i = 0; i < 9; i++) {
		m.insert(make_pair(h[i], i + 1));
	}

	find_Seven_Dwarf(temp, h, m);
	return 0;
}
