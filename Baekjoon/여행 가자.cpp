#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#define rint register int

using namespace std;

constexpr int MAX = 202;

int parent[MAX];
vector<int> city;

int find(int x)
{
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void merge(int x, int y)
{
	x = find(x);
	y = find(y);

	if (x < y) parent[y] = x;
	else parent[x] = y;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	
	int N, M;
	cin >> N >> M;
	for (rint i = 1; i <= N; ++i) parent[i] = i;

	int info;
	for (rint i = 1; i <= N; ++i)
	{
		for (rint j = 1; j <= N; j++)
		{
			cin >> info;
			if (info) merge(i, j);
		}
	}

	int city_num;
	for (rint i = 0; i < M; ++i)
	{
		cin >> city_num;
		city.push_back(city_num);
	}

	bool flag = true;
	for (rint i = 0; i < M - 1; ++i)
	{
		if (find(city[i]) == find(city[i + 1])) continue;
		else
		{
			flag = false;
			break;
		}
	}

	if (flag) cout << "YES" << '\n';
	else cout << "NO" << '\n';

	return 0;
}
