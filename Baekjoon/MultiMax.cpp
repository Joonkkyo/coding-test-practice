#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

int main(void) {
	std::ios::sync_with_stdio(false);
	int T;
	int N, num;  //ī�忡 ���� ����
	int answer;
	vector<int> deck;  //ī�带 ������ ����
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;  //ī���� ����
		for (int i = 0; i < N; i++) {
			cin >> num;
			deck.push_back(num);
		}
		sort(deck.begin(), deck.end(), less<int>());
		//�� ���� ���� �̴� ���
		int v1 = deck[N - 2] * deck[N - 1];  //ū �� 2�� (��� * ���)
		int v2 = deck[0] * deck[1];  //���� �� 2�� (���� * ����)
									 //�� ���� ���� �̴� ���
		int v3 = deck[N - 3] * deck[N - 2] * deck[N - 1];  //ū �� 3�� (��� * ��� * ���)
		int v4 = deck[0] * deck[1] * deck[N - 1];  //���� �� 2��, ū �� 1�� (���� * ���� * ���)
		answer = max({ v1, v2, v3, v4 });
		cout << answer << '\n';
		deck.clear();
	}
	return 0;
}
