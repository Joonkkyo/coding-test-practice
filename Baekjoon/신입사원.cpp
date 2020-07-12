#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <functional>
using namespace std;

int main(void) {
	int T, N, cnt;
	string str;
	cin >> T;
	vector<pair<int, int>> score;
	for (int i = 0; i < T; i++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			int a, b;
			cin >> a >> b;
			score.push_back(make_pair(a, b));  //서류점수, 면접점수
		}
		sort(score.begin(), score.end());
		cnt = 1;
		int min_score = score[0].second;
		for (int i = 0; i < N; i++) {
			if (score[i].second < min_score) {
				cnt++;
				min_score = score[i].second;
			}
		}
		cout << cnt << endl;
		score.clear();
	}
	return 0;
}


