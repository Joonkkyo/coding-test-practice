#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> v;
int cache[10001];
//dp(n) : n개의 붕어빵을 팔았을 때의 최대 수익
int dp(int n) {
	//base case
	if (n == 0)
		return 0;
	//cache read/write
	int& ret = cache[n];
	if (ret != -1)
		return ret;
	//general case
	ret = 0;
	for (int i = 0; i < n; i++) {
		ret = max(ret, dp(i) + v[n - i]);
	}
	return ret;
}
int main(void) {
	int num;
	cin >> N;
	v.resize(N + 1);
	memset(cache, -1, sizeof(cache));
	for (int i = 1; i <= N; i++) {
		cin >> v[i];
	}

	cout << dp(N) << endl;
	return 0;
}