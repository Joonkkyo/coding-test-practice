#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int N; // 전체 사람 수
	int w, h; // 몸무게, 키
	vector<int> weight;
	vector<int> height;
	vector<int> rank;
	int r; // 순위
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> w >> h;
		weight.push_back(w);
		height.push_back(h);
	}

	for (int i = 0; i < N; i++)
	{
		r = 1;
		for (int j = 0; j < N; j++)
		{
			if (i == j)
				continue;
			if (weight[i] < weight[j] && height[i] < height[j])
				r++;
		}
		rank.push_back(r);
	}

	for (int i = 0; i < N; i++)
		cout << rank[i] << endl;
}
