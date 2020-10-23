#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>
using namespace std;

vector<vector<int>> adj; //인접 행렬
vector<bool> visited; //방문 여부

void dfs(int here) { //하나의 정점을 기준으로 dfs 탐색을 하는 함수
	visited[here] = true; //정점을 방문함
	for (int i = 0; i < adj[here].size(); i++) {//현재 정점에서 갈 수 있는 정점 탐색
		int there = adj[here][i];
		if (!visited[there]) {  //방문한 적이 없다면
			dfs(there); //그 정점에 대해 다시 dfs 탐색
		}
	}
}

int main(void) {
	int V, E;
	int cnt = 0;
	cin >> V >> E;  //V : 정점 갯수 E : 간선 갯수
	adj.resize(V + 1);
	visited.resize(V + 1, false);
	for (int i = 0; i < E; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u); //정보 추가
	}
	for (int i = 1; i <= V; i++) {  //한 그래프에 대해 모든 탐색을 마치면 cnt 증가
		if (!visited[i]) {
			dfs(i);
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}