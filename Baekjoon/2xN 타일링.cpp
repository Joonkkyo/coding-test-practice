#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int cache[1001];
int N;

int Dp(int idx) {
	if (idx == 1)  //Memoization
		return cache[idx] = 1;
	if (idx == 2)
		return cache[idx] = 2;
	int& ret = cache[idx];
	if (ret != -1)
		return ret;
	else
		return ret = (Dp(idx - 1) + Dp(idx - 2)) % 10007;
}
int main(void) {
	memset(cache, -1, sizeof(cache));
	cin >> N;
	cout << Dp(N) << '\n';
	return 0;
}