#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

float find_pyEx(int S, int W);

int main(void)
{
	std::ios::sync_with_stdio(false);
	int T;
	int num_of_team, num_of_game;
	int first_t, second_t;
	int first_get, second_get;
	int S, A;
	float pyEx, min_pyEx, max_pyEx;
	vector<float> pyEx_Vec;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int get_score[1000] = { 0, };  //iÆÀÀÌ µæÁ¡ÇÑ Á¡¼ö
		int lose_score[1000] = { 0, };  //iÆÀÀÌ ½ÇÁ¡ÇÑ Á¡¼ö
		cin >> num_of_team >> num_of_game;
		for (int j = 0; j < num_of_game; j++) {
			cin >> first_t >> second_t >> first_get >> second_get;
			get_score[first_t] += first_get;
			get_score[second_t] += second_get;
			lose_score[first_t] += second_get;
			lose_score[second_t] += first_get;
		}

		for (int i = 1; i <= num_of_team; i++) {
			S = get_score[i];
			A = lose_score[i];
			pyEx = find_pyEx(S, A);
			pyEx_Vec.push_back(pyEx);
		}
		sort(pyEx_Vec.begin(), pyEx_Vec.end());
		min_pyEx = pyEx_Vec[0];
		max_pyEx = pyEx_Vec[num_of_team - 1];

		cout << int(max_pyEx * 1000) << '\n';
		cout << int(min_pyEx * 1000) << '\n';
		pyEx_Vec.clear();
	}
	return 0;
}

float find_pyEx(int S, int A) {
	float W = (float)(S * S) / (float)(S*S + A * A);
	return W;
}