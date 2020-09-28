#include <iostream>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	long int d[91];
	d[0] = 0;
	d[1] = 1;
	for (int i = 2; i <= n; i++)
		d[i] = d[i - 1] + d[i - 2];

	cout << d[n] << '\n';
	return 0;
}