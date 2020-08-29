#include <iostream>
#include <vector>
using namespace std;

int gause[45];
int K;

bool comb(int size, int sum) {
	if (size == 3) {
		if (sum == K)
			return true;
		return false;
	}
	for (int i = 1; i < 45; i++)
		if (sum + gause[i] <= K && comb(size + 1, sum + gause[i]))
			return true;
	return false;
}

int main() {
	for (int i = 1; i < 45; i++) {
		gause[i] = i * (i + 1) / 2;
	}
	vector<bool> ret;
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> K;
		ret.push_back(comb(0, 0));
	}
	for (int t = 0; t < T; t++) {
		cout << ret[t] << endl;
	}
	return 0;
}