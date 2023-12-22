#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#define rint register int
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt", "r", stdin);

	int n, diff;
	vector<int> diffs;
	cin >> n;
	if (n == 0) cout << 0 << '\n';
	else {
		int exNum = round(n * 0.15);
		while (n--) {
			cin >> diff;
			diffs.push_back(diff);
		}

		sort(diffs.begin(), diffs.end());
		int sum = 0;
		for (rint i = exNum; i < diffs.size() - exNum; ++i) {
			sum += diffs[i];
		}

		cout << round(sum / double(diffs.size() - 2 * exNum)) << '\n';
	}
	return 0;
}
