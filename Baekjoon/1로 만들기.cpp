#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int dp[1000001]; //dp[i] : 연산 수의 최솟값

int main(void) {
	int N;
	cin >> N;

	dp[1] = 0;
	for (int i = 2; i <= N; i++) {
		dp[i] = dp[i - 1] + 1; //연산했기 때문에 1 추가
		if (i % 3 == 0)
			dp[i] = min(dp[i], dp[i / 3] + 1);
		else if (i % 2 == 0)
			dp[i] = min(dp[i], dp[i / 2] + 1);
	}

	cout << dp[N] << endl;
}
