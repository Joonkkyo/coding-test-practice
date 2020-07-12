#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

int main(void) {
	int T; //�׽�Ʈ���̽� ũ��
	cin >> T;
	for (int k = 0; k < T; k++) {
		int n; //�迭�� ũ��
		cin >> n;
		vector<int> v(n + 1, 0);
		vector<int> sum(n + 1, 0);

		for (int i = 1; i <= n; i++)
			cin >> v[i];
		//�������� ���Ѵ�.
		for (int i = 1; i <= n; i++)
			sum[i] = sum[i - 1] + v[i];
		//�������� �����Ѵ�. (��������)
		sort(sum.begin(), sum.end());
		//�������� ��ȸ�ϸ鼭 ���� �ּҰ� �Ǵ� ������ ã�´�.
		int min_diff = sum[1] - sum[0];
		for (int i = 1; i < n; i++) {
			min_diff = min(min_diff, sum[i + 1] - sum[i]);
		}
		cout << min_diff << endl;
	}
	return 0;
}
