#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int T;
	int n; //���� ��
	int quote_num; //�ο�� Ƚ��
	vector<int> qt;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;
		int cnt = 0;
		int q_idx = 0;
		for (int i = 0; i < n; i++) {
			cin >> quote_num;
			qt.push_back(quote_num);
		}
		sort(qt.begin(), qt.end());

		if (n <= qt[0])
			cout << n << endl;

		else {
			for (int i = 0; i < n; i++) {
				int temp = qt[i];

				if (temp <= n - i) {  //k�� �ο�� ���� k�� �̻��� ��
					if (temp >= q_idx)
						q_idx = temp;
					else
						break;
				}
				else
					cnt++;
			}
			if (cnt > q_idx)
				q_idx = cnt;
			cout << q_idx << endl;
		}
		qt.clear();
	}
	return 0;
}