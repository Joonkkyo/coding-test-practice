#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> cache;
int N;
vector<int> v;

int dp(int idx) {
	int& ret = cache[idx];
	if (ret != -1)
		return ret;
	ret = 1;
	for (int i = idx + 1; i <= N; i++) {
		if (v[i] > v[idx]) {
			ret = max(ret, 1 + dp(i));
		}
	}
	return ret;
}

int main(void) {
	int num;
	cin >> N;
	v.push_back(-1);
	cache.resize(N + 1, -1);
	for (int i = 0; i < N; i++) {
		cin >> num;
		v.push_back(num);
	}
	cout << N - (dp(0) - 1) << endl;
	return 0;
}