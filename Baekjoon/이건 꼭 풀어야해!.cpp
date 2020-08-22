#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int num[300001];
int sum[300001];
int main(void)
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int N, Q;
	int n;
	int L, R;

	cin >> N >> Q;

	for (int i = 1; i <= N; i++)
	{
		cin >> num[i];
	}
	sort(num + 1, num + N + 1);

	for (int i = 1; i <= N; i++)
	{
		sum[i] = sum[i - 1] + num[i];
	}

	for (int i = 0; i < Q; i++)
	{
		cin >> L >> R;
		cout << sum[R] - sum[L - 1] << endl;
	}

	return 0;
}