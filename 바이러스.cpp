#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>
using namespace std;

vector<vector<int>> adj; //���� ���
vector<bool> visited; //�湮 ����

void dfs(int here) { //�ϳ��� ������ �������� dfs Ž���� �ϴ� �Լ�
	visited[here] = true; //������ �湮��
	for (int i = 0; i < adj[here].size(); i++) {//���� �������� �� �� �ִ� ���� Ž��
		int there = adj[here][i];
		if (!visited[there]) {  //�湮�� ���� ���ٸ�
			dfs(there); //�� ������ ���� �ٽ� dfs Ž��
		}
	}
}

int main(void) {
	int V, E;
	int cnt = 0;
	cin >> V >> E;  //V : ���� ���� E : ���� ����
	adj.resize(V + 1);
	visited.resize(V + 1, false);
	for (int i = 0; i < E; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u); //���� �߰�
	}
	for (int i = 1; i <= V; i++) {  //�� �׷����� ���� ��� Ž���� ��ġ�� cnt ����
		if (!visited[i]) {
			dfs(i);
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}