#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

void findMidValue(vector<int> &v) {  //배열의 중간값 출력
	sort(v.begin(), v.end(), greater<int>());
	int idx = v.size() / 2;
	cout << v[idx] << " ";
}

int main(void) {
	int T, M;
	int num;
	int cnt = 0;
	vector<int> n;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> M;
		for (int j = 0; j < M; j++) {
			cin >> num;
			n.push_back(num);
			if (cnt == 0) {
				cout << (M + 1) / 2 << endl;
				cnt++;
			}

			if (j % 2 == 0)
				findMidValue(n);
		}
		n.clear();
		cnt = 0;
		cout << endl;
	}
}
