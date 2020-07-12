#include <iostream>
#include <algorithm>
using namespace std;

int N;
int dp[3] = { 0, };  //i-1��° ���� ĥ�ϴ� ���

int solve(void)
{

	int RGB[3];
	int red, green, blue;
	int ret;
	cin >> red >> green >> blue;
	RGB[0] = red, RGB[1] = green, RGB[2] = blue;

	for (int i = 1; i < N; i++)
	{
		cin >> red >> green >> blue;

		for (int j = 0; j < 3; j++) {
			dp[j] = RGB[j];  //ĥ�ϴ� ��� �ʱ�ȭ
		}

		RGB[0] = red + min(dp[1], dp[2]);  //���� �� ���� �Ÿ��� ����
		RGB[1] = green + min(dp[0], dp[2]);
		RGB[2] = blue + min(dp[0], dp[1]);
	}
	return min(min(RGB[0], RGB[1]), RGB[2]);  //RGB�Ÿ��� �ּڰ� ���
}

int main(void)
{
	cin >> N;
	if (N < 1 || N > 1000)
		exit(-1);

	cout << solve() << endl;
	return 0;
}