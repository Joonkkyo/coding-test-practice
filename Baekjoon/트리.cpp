#include <iostream>
#include <vector>
#include <cstring>
#define rint register int
using namespace std;

constexpr int MAX_N = 51;
vector<int> tree[MAX_N]; // 자식 노드 저장
int visited[MAX_N];
int delNode, leafCnt = 0;

void dfs(int n) {
	if (visited[n] || n == delNode) return;
	visited[n] = true;

	if (tree[n].size() == 0 || (tree[n][0] == delNode && tree[n].size() == 1)) { 
    // 자식 노드가 없거나, 하나뿐인데 삭제된 노드인 경우 leaf node
		leafCnt++;
	}

	for (rint i = 0; i < tree[n].size(); ++i) {
		dfs(tree[n][i]);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(visited, false, sizeof(visited));
	int N, p, root;
	cin >> N;
	for (rint i = 0; i < N; ++i) {
		cin >> p;
		if (p == -1) root = i;
		else tree[p].push_back(i);
	}

	cin >> delNode;
	dfs(root);
	cout << leafCnt;

	return 0;
}
