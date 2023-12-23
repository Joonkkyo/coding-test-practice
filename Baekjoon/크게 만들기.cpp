#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#define rint register int
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt", "r", stdin);

	int N, K;
	string nums;
	stack<char> st, res;
	cin >> N >> K;
	cin >> nums;

	int cnt = 0;
	for (rint i = 0; i < nums.size(); ++i) {
		while (K > cnt && !st.empty() && st.top() < nums[i]) {
			st.pop();
			cnt++;
		}
		st.push(nums[i]);
	}

	while (!st.empty()) {
		res.push(st.top());
		st.pop();
	}

	int lenCnt = 0;
	while (!res.empty() && lenCnt < N - K) {
		cout << res.top();
		res.pop();
		lenCnt++;
	}
	cout << '\n';

	return 0;
}
