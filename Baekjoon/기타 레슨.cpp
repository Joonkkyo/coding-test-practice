#include <iostream>
#include <vector>
#define rint register int
using namespace std;

constexpr int MAX_N = 100001;
int bluray[MAX_N];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	
	int start = -1, end;
	int sum = 0;
	for (rint i = 0; i < N; ++i)
	{
		cin >> bluray[i];
		sum += bluray[i];
		start = max(start, bluray[i]);
	}
	
	end = sum;

	while (start <= end)
	{
		int cnt = 0, tmpSum = 0;
		int mid = (start + end) / 2;

		for (rint i = 0; i < N; ++i)
		{
			if (tmpSum + bluray[i] > mid)
			{
				tmpSum = 0;
				cnt += 1;
			}

			tmpSum += bluray[i];
		}

		if (tmpSum > 0) cnt += 1;

		if (cnt <= M) end = mid - 1;
		else start = mid + 1;
	}

	cout << start;
	return 0;
}
