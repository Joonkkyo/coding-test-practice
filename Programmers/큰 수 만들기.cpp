#include <string>
#include <math.h>
using namespace std;

string solution(string number, int k)
{
	string answer = "";
	int size = number.size();
	int max = 0;
	int idx = 0;
	int cnt = 0;

	for (int i = 0; i < size - k; i++)
	{
		int temp = 0;
		for (int j = idx; j < k + cnt + 1; j++)
		{
			if (max < number[j])
			{
				max = number[j];
				temp = j;
			}
		}
		idx = temp + 1;
		answer += max;
		cnt++;
		max = 0;
	}
	
	return answer;
}
