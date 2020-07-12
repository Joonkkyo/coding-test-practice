#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	int num;
	int max;
	long int dp[100001] = { 0, }; //dp[i] : i에서 끝나는 연속합의 최댓값
	vector<int> numVec;

	cin >> n;
	numVec.resize(n + 1, 0);
	for (int i = 1; i <= n; i++)
		cin >> numVec[i];

	for (int i = 1; i <= n; i++) {
		if (dp[i - 1] + numVec[i] > numVec[i])  //연속된 수를 더한 값이 그 수보다 크면
			dp[i] = dp[i - 1] + numVec[i]; //그 수를 더함
		else
			dp[i] = numVec[i];
	}
	max = dp[1];
	for (int i = 2; i <= n; i++) {
		if (max < dp[i])
			max = dp[i];
	}
	cout << max << '\n';
	return 0;
}