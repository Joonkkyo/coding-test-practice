#include <iostream>
#define rint register int
typedef long long ll;
using namespace std;

constexpr int MAX_N = 1000001;
ll FWTree[MAX_N];
ll numArr[MAX_N];
int N;

void FWupdate(int idx, ll val)
{
	while (idx <= N)
	{
		FWTree[idx] += val;
		idx += idx & -idx;
	}
}

ll FWsum(int idx)
{
	ll sum = 0;
	while (idx > 0)
	{
		sum += FWTree[idx];
		idx -= idx & -idx;
	}
	
	return sum;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int M, K;
	cin >> N >> M >> K;

	for (rint i = 1; i <= N; ++i)
	{
		cin >> numArr[i];
		FWupdate(i, numArr[i]);
	}

	ll a, b, c;
	for (rint i = 0; i < M + K; ++i)
	{
		cin >> a >> b >> c;
		if (a == 1)
		{
			ll diff = c - numArr[b];
			numArr[b] = c;
			FWupdate(b, diff);
		}

		else
			cout << FWsum(c) - FWsum(b - 1) << '\n';
	}

	return 0;
}
