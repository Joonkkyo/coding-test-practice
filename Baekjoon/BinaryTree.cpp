#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <cmath>
#define SIZE (1 << 22)  //2^22 
using namespace std;

int node[SIZE] = { 0, }; //����ġ�� ��� ���·� ������ �迭
int path[SIZE] = { 0, }; //������ ���������� ���� ���
int sum[SIZE] = { 0, }; //������ ���������� ���� ����� �Ÿ��� ��
int main(void) {
	std::ios::sync_with_stdio(false); cin.tie(0);
	int T;
	int k;  //��ȭ����Ʈ���� ����
	int w; //������ ����ġ �Է�
	int left, right; //�ش� ���̿����� ����, ������ ����� �ε���
	cin >> T;
	while (T--) {
		cin >> k;
		int size = pow(2, k + 1);
		for (int i = 2; i < size; i++) {
			cin >> w;
			node[i] = w;
		}

		for (int i = size; i > 0; i--) {  //���� ������ �Ųٷ� Ž��
			left = i * 2;  //���� ����� �ε���
			right = left + 1;  //������ ����� �ε���
			path[i] = max(path[left] + node[left], path[right] + node[right]);  //�ش� ������ �����ϴ� ���� ���
			sum[i] = sum[left] + sum[right] + (path[i] - path[left]) + (path[i] - path[right]);  //��庰 �����ο� ���� �Ÿ��� �� ���
		}
		cout << sum[1] << endl;
		memset(node, 0, sizeof(node));
		memset(path, 0, sizeof(path));
		memset(sum, 0, sizeof(sum));
	}
	return 0;
}
