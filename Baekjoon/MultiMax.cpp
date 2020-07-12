#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

int main(void) {
	std::ios::sync_with_stdio(false);
	int T;
	int N, num;  //카드에 적힌 숫자
	int answer;
	vector<int> deck;  //카드를 저장할 벡터
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;  //카드의 갯수
		for (int i = 0; i < N; i++) {
			cin >> num;
			deck.push_back(num);
		}
		sort(deck.begin(), deck.end(), less<int>());
		//두 개의 수를 뽑는 경우
		int v1 = deck[N - 2] * deck[N - 1];  //큰 수 2개 (양수 * 양수)
		int v2 = deck[0] * deck[1];  //작은 수 2개 (음수 * 음수)
									 //세 개의 수를 뽑는 경우
		int v3 = deck[N - 3] * deck[N - 2] * deck[N - 1];  //큰 수 3개 (양수 * 양수 * 양수)
		int v4 = deck[0] * deck[1] * deck[N - 1];  //작은 수 2개, 큰 수 1개 (음수 * 음수 * 양수)
		answer = max({ v1, v2, v3, v4 });
		cout << answer << '\n';
		deck.clear();
	}
	return 0;
}
