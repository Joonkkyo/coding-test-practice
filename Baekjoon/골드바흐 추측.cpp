#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void find_Partition(vector<int>& v, int num) {
	vector<int> first;
	vector<int> second;

	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v.size(); j++) {
			if (v[i] + v[j] == num) {
				if (v[i] <= v[j]) {
					first.push_back(v[i]);
					second.push_back(v[j]);
				}
				else {
					first.push_back(v[j]);
					second.push_back(v[i]);
				}
			}
		}
	}

	vector<pair<int, int>> subVec;
	for (int i = 0; i < first.size(); i++) {
		int sub = second[i] - first[i];
		subVec.push_back(make_pair(sub, i));
	}
	sort(subVec.begin(), subVec.end());
	int idx = subVec[0].second;
	cout << first[idx] << " " << second[idx] << endl;
}

int main(void) {
	int T;
	int num, origin_num;
	int cnt;
	vector<int> decimal;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> num;
		origin_num = num;
		while (num > 1) {
			cnt = 0;
			if (num == 2) {
				decimal.push_back(num);
				break;
			}
			for (int j = 2; j < num; j++) {

				if (num % j == 0)
					break;
				else
					cnt++;
			}
			if (num != 2 && cnt == num - 2)
				decimal.push_back(num);
			num--;
		}
		sort(decimal.begin(), decimal.end());
		find_Partition(decimal, origin_num);
	}
	return 0;
}


