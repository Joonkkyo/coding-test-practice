#include <iostream>
using namespace std;

int dp_0[40] = { 0, };
int dp_1[40] = { 0, };
int main(void)
{
	int testCase;
	int N;
	cin >> testCase;
	while (testCase--)
	{
		cin >> N;
		dp_0[0] = 1; dp_1[0] = 0;
		dp_0[1] = 0; dp_1[1] = 1;

		if (N == 0)
			cout << dp_0[0] << " " << dp_1[0] << endl;
		else if (N == 1)
			cout << dp_0[1] << " " << dp_1[1] << endl;
		else
		{
			for (int i = 2; i <= N; i++)
			{
				dp_1[i] = dp_1[i - 1] + dp_1[i - 2];
				dp_0[i] = dp_1[i - 1];
			}
			cout << dp_0[N] << " " << dp_1[N] << endl;;
		}
	}

	return 0;
}
