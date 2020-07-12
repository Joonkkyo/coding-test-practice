#include <iostream>
#include <vector>

using namespace std;

void init(int weight, vector<int>& v) {  //다리 무게 0으로 초기화

	for (int i = 0; i < weight; i++)
	{
		v.push_back(0);
	}
}

int sum(int weight, vector<int>& v) {  //다리에 올라와있는 트럭의 무게의 합을 구하는 함수
	int total = 0;
	for (int i = 0; i < weight - 1; i++)
		total += v[i];

	return total;
}

int main()
{
	std::ios::sync_with_stdio(false);
	int T;  //테스트케이스
	int N, W, L;
	int tr;
	cin >> T;
	for (int x = 0; x < T; x++)
	{

		cin >> N >> W >> L;
		vector<int> bridge;
		vector<int> truck;
		int time = 0;
		int idx = 0;

		init(W, bridge);
		for (int i = 0; i < N; i++)
		{
			cin >> tr;
			truck.push_back(tr);
		}

		while (1)
		{
			if (truck[idx] + sum(W, bridge) <= L)  //다리에 트럭을 올릴 수 있음 (하중초과 X)
			{
				bridge.insert(bridge.begin(), truck[idx++]);
				bridge.pop_back();
				time++;
			}
			else  //하중을 초과한 경우
			{
				bridge.insert(bridge.begin(), 0);
				bridge.pop_back();
				time++;
			}
			if (idx == N)  //남은 트럭이 없는 경우
			{
				time = time + W;
				break;
			}
		}
		cout << time << endl;
	}
	return 0;
}