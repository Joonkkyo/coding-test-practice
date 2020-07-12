#include <iostream>
#include <vector>
using namespace std;

int cal_digit(int n);
int main(void)
{
	int N; // �ڿ���
	int digit;
	int decomp, decomp_sum = 0;
	vector<int> decomp_vec;
	cin >> N;
	digit = cal_digit(N);

	for (int i = N - digit * 9; i < N; i++)
	{
		int tmp = i;

		while (tmp > 0)
		{
			decomp = tmp % 10;
			decomp_sum += decomp;
			tmp /= 10;
		}

		if (decomp_sum + i == N)
			decomp_vec.push_back(i);

		decomp_sum = 0;
	}

	if (decomp_vec.size() == 0)
		cout << 0 << endl;
	else
		cout << decomp_vec[0] << endl;
}

int cal_digit(int n) // �ڸ��� ���
{
	int dg = 0;
	while (n > 0)
	{
		n /= 10;
		dg++;
	}
	return dg;
}

