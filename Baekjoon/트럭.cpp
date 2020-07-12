#include <iostream>
#include <vector>

using namespace std;

void init(int weight, vector<int>& v) {  //�ٸ� ���� 0���� �ʱ�ȭ

	for (int i = 0; i < weight; i++)
	{
		v.push_back(0);
	}
}

int sum(int weight, vector<int>& v) {  //�ٸ��� �ö���ִ� Ʈ���� ������ ���� ���ϴ� �Լ�
	int total = 0;
	for (int i = 0; i < weight - 1; i++)
		total += v[i];

	return total;
}

int main()
{
	std::ios::sync_with_stdio(false);
	int T;  //�׽�Ʈ���̽�
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
			if (truck[idx] + sum(W, bridge) <= L)  //�ٸ��� Ʈ���� �ø� �� ���� (�����ʰ� X)
			{
				bridge.insert(bridge.begin(), truck[idx++]);
				bridge.pop_back();
				time++;
			}
			else  //������ �ʰ��� ���
			{
				bridge.insert(bridge.begin(), 0);
				bridge.pop_back();
				time++;
			}
			if (idx == N)  //���� Ʈ���� ���� ���
			{
				time = time + W;
				break;
			}
		}
		cout << time << endl;
	}
	return 0;
}