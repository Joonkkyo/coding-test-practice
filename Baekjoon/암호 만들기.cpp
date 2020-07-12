#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <map>
using namespace std;

int N, M;
int vowelCnt = 0;
int consonantCnt = 0;

void print_vector(vector<char>& v) {
	for (int i = 0; i < v.size(); i++)
		cout << v[i];
	cout << '\n';
}

void recursive(vector<char>& v, vector<char>& a, map<char, int>& m) {
	if (v.size() == N) {
		vowelCnt = 0;
		consonantCnt = 0;
		for (int i = 0; i < v.size(); i++) {
			if (v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u')
				vowelCnt++;

			if (v[i] != 'a' && v[i] != 'e' && v[i] != 'i' && v[i] != 'o' && v[i] != 'u')
				consonantCnt++;
		}

		if (vowelCnt >= 1 && consonantCnt >= 2) {
			print_vector(v);
			return;
		}
	}

	int first = 0;
	if (!v.empty()) {
		first = m[v.back()];
	}

	for (int i = first + 1; i <= M; i++) {
		v.push_back(a[i - 1]);
		recursive(v, a, m);
		v.pop_back();
	}
}

int main(void) {
	vector<char> temp;
	vector<char> alpha;
	map<char, int> m;
	char c;

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> c;
		alpha.push_back(c);
	}
	sort(alpha.begin(), alpha.end());

	for (int i = 0; i < alpha.size(); i++) {
		m.insert(make_pair(alpha[i], i + 1));
	}

	recursive(temp, alpha, m);
	return 0;
}
