#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main(void)
{
	int testCase;
	int answer = 0;
	double dist;
	double x1, y1, r1, x2, y2, r2;
	cin >> testCase;
	while (testCase--)
	{
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		dist = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));

		if (dist == 0)
		{
			if (r1 == r2)
				answer = -1;
			else
				answer = 0;
		}

		else if (dist < r1 + r2)
		{
			if (dist + min(r1, r2) < max(r1, r2))  // 두 원이 포함관계
				answer = 0;
			else if (dist + min(r1, r2) == max(r1, r2))  // 두 원이 내접
				answer = 1;
			else
				answer = 2;
		}
		else if (dist == r1 + r2)
			answer = 1;
		else
			answer = 0;

		cout << answer << endl;
	}
	return 0;
}