#include <iostream>
#include <cstdio>
using namespace std;

void hanoi(int n, int from, int by, int to)
{
	if (n == 1)
	{
		printf("%d %d\n", from, to);
		return;
	}
	else
	{
		hanoi(n - 1, from, to, by);
		printf("%d %d\n", from, to);
		hanoi(n - 1, by, from, to);
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	cout << (1 << N) - 1 << endl;
	hanoi(N, 1, 2, 3);

	return 0;
}