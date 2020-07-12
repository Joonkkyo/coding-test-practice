#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int sum = 0;
	int idx1, idx2;
	vector<int> height;
	vector<int> result;
	int n_h; // ≥≠¿Ô¿ÃµÈ ≈∞
	for (int i = 0; i < 9; i++)
	{
		cin >> n_h;
		height.push_back(n_h);
		sum += n_h;
	}
	
	for (int i = 0; i < 8; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			if (sum - height[i] - height[j] == 100)
			{
				idx1 = i;
				idx2 = j;
				break;
			}
		}
	}

	for (int i = 0; i < 9; i++)
	{
		if (i == idx1 || i == idx2)
			continue;
		result.push_back(height[i]);
	}

	sort(result.begin(), result.end());
	
	for (int i = 0; i < 7; i++)
	{
		cout << result[i] << endl;
	}

	return 0;
}