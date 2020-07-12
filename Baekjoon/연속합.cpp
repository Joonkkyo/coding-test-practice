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
	long int dp[100001] = { 0, }; //dp[i] : i���� ������ �������� �ִ�
	vector<int> numVec;

	cin >> n;
	numVec.resize(n + 1, 0);
	for (int i = 1; i <= n; i++)
		cin >> numVec[i];

	for (int i = 1; i <= n; i++) {
		if (dp[i - 1] + numVec[i] > numVec[i])  //���ӵ� ���� ���� ���� �� ������ ũ��
			dp[i] = dp[i - 1] + numVec[i]; //�� ���� ����
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