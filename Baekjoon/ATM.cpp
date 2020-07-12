#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	std::ios::sync_with_stdio(false);
	int N, time;
	int sum = 0;
	int total = 0;
	vector<int> P;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> time;
		P.push_back(time);
	}
	sort(P.begin(), P.end());
	for (int i = 0; i < N; i++) {
		sum += P[i];
		total += sum;
	}
	cout << total << '\n';
	return 0;
}