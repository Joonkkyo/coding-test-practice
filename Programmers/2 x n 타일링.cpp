#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	int answer = 0;
	int d[60000] = { 0, };
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
	{
		d[0] = 0, d[1] = 1, d[2] = 2;
		for (int i = 3; i <= n; i++)
		{
			d[i] = (d[i - 1] + d[i - 2]) % 1000000007;
		}
		answer = d[n];
		return answer;
	}
}