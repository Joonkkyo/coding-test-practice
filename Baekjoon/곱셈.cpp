#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int num1, num2;
	int tmp1, tmp2;
	vector<int> n;
	vector<int> answer;
	cin >> num1 >> num2;
	
	tmp1 = num2;
	while (num2 > 0)
	{
		tmp2 = num2 % 10;
		n.push_back(tmp2);
		num2 /= 10;
	}

	for (int i = 0; i < 3; i++)
		answer.push_back(n[i] * num1);

	answer.push_back(num1 * tmp1);

	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << endl;

	return 0;
}