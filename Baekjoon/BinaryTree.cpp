#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <cmath>
#define SIZE (1 << 22)  //2^22 
using namespace std;

int node[SIZE] = { 0, }; //가중치를 노드 형태로 저장할 배열
int path[SIZE] = { 0, }; //노드부터 리프까지의 최장 경로
int sum[SIZE] = { 0, }; //노드부터 리프까지의 최장 경로의 거리의 합
int main(void) {
	std::ios::sync_with_stdio(false); cin.tie(0);
	int T;
	int k;  //포화이진트리의 높이
	int w; //에지의 가중치 입력
	int left, right; //해당 높이에서의 왼쪽, 오른쪽 노드의 인덱스
	cin >> T;
	while (T--) {
		cin >> k;
		int size = pow(2, k + 1);
		for (int i = 2; i < size; i++) {
			cin >> w;
			node[i] = w;
		}

		for (int i = size; i > 0; i--) {  //리프 노드부터 거꾸로 탐색
			left = i * 2;  //왼쪽 노드의 인덱스
			right = left + 1;  //오른쪽 노드의 인덱스
			path[i] = max(path[left] + node[left], path[right] + node[right]);  //해당 노드까지 도달하는 최장 경로
			sum[i] = sum[left] + sum[right] + (path[i] - path[left]) + (path[i] - path[right]);  //노드별 최장경로에 대한 거리의 합 계산
		}
		cout << sum[1] << endl;
		memset(node, 0, sizeof(node));
		memset(path, 0, sizeof(path));
		memset(sum, 0, sizeof(sum));
	}
	return 0;
}
