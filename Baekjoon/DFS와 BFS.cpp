#include<iostream>
#include<queue>
using namespace std;

#define MAX 1001  
int N, M, V;  //노드 개수, 간선 개수, 시작할 노드 번호
int adj[MAX][MAX];  //인접행렬 배열 선언
int visit[MAX];           

void dfs(int v) {
	cout << v << ' ';
	visit[v] = true;            //방문한 노드를 visit 0에서 1로 변경
	for (int i = 1; i <= N; i++) {
		if (visit[i] || adj[v][i] == 0)  //방문한 노드이거나, 더 이상 연결된 노드가 없으면 탈출
			continue;
		dfs(i);  //재귀적 dfs 진행
	}
}

void bfs(int v) {
	queue<int> q;  
	q.push(v);
	visit[v] = 0;  //방문한 노드를 visit 1에서 0으로 변경
	while (!q.empty()) {
		v = q.front();
		cout << q.front() << ' ';
		q.pop();
		for (int i = 1; i <= N; i++) {
			if (!visit[i] || adj[v][i] == 0)
				continue;
			q.push(i);
			visit[i] = 0;
		}
	}
}

int main() {
	int x, y;
		cin >> N >> M >> V;  //N은 노드개수, M은 간선의개수, V는 처음 위치의 기준이 되는 노드
	for (int i = 0; i<M; i++) {  //간선의 개수만큼 서로 이어줄 x와 y노드를 입력받습니다.
		cin >> x >> y;
		adj[x][y] = adj[y][x] = 1;  //인접행렬 표시
	}
	dfs(V);
	cout << '\n';
	bfs(V);
	cout << '\n';
	return 0;
}
