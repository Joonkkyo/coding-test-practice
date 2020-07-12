#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

int main(void) {
	int T; //테스트케이스 크기
	cin >> T;
	for (int k = 0; k < T; k++) {
		int n; //배열의 크기
		cin >> n;
		vector<int> v(n + 1, 0);
		vector<int> sum(n + 1, 0);

		for (int i = 1; i <= n; i++)
			cin >> v[i];
		//누적합을 구한다.
		for (int i = 1; i <= n; i++)
			sum[i] = sum[i - 1] + v[i];
		//누적합을 정렬한다. (오름차순)
		sort(sum.begin(), sum.end());
		//누적합을 순회하면서 차가 최소가 되는 구간을 찾는다.
		int min_diff = sum[1] - sum[0];
		for (int i = 1; i < n; i++) {
			min_diff = min(min_diff, sum[i + 1] - sum[i]);
		}
		cout << min_diff << endl;
	}
	return 0;
}
