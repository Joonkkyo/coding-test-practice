#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <map>
using namespace std;

int num_Of_Set = 0;

bool isCorrect(vector<int>& v, int S) {
	int sum = 0;
	for (int i = 0; i < v.size(); i++)
		sum += v[i];
	if (sum == S)
		return true;
	else
		return false;
}

void find_Case(vector<int>& v, vector<int>& n, int N, int S) {
	if (v.size() == N) {
		vector<int> tmp;
		for (int i = 0; i < N; i++) {
			if (v[i] == 1)
				tmp.push_back(n[i]);
			else
				continue;
		}
		if (isCorrect(tmp, S))
			num_Of_Set++;
		return;
	}

	v.push_back(1);
	find_Case(v, n, N, S);
	v.pop_back();

	v.push_back(0);
	find_Case(v, n, N, S);
	v.pop_back();
}

int main(void) {
	ios::sync_with_stdio(false);
	int N, S;
	int num;
	vector<int> n;
	vector<int> temp;

	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		cin >> num;
		n.push_back(num);
	}
	find_Case(temp, n, N, S);
	if (S == 0)
		num_Of_Set--;
	cout << num_Of_Set << endl;
	return 0;
}