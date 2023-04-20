#include <iostream>
#include <vector>
using namespace std;

constexpr int MAX = 11;
int graph[MAX][MAX];
bool visited[MAX];
int N, answer;

int find_friends(int v)
{
	int count = 0;
	for (int i = 1; i <= N; i++)
		if (graph[v][i] == 1)
			count++;

	return count;
}

void find_longest_path(int v, int dist)
{
	if (dist > answer)
		answer = dist;

	for (int i = 1; i <= N; i++)
	{
		if (!visited[i] && graph[v][i] == 1)
		{
			visited[i] = true;
			find_longest_path(i, dist + 1);
			visited[i] = false;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.tie(NULL);
  
	int test_case;
	cin >> test_case;
	for (int tc = 1; tc <= test_case; tc++)
	{
		int K;
		cin >> N >> K;
		memset(graph, 0, sizeof(graph));
		memset(visited, false, sizeof(visited));
		vector<int> friend_vec;
		answer = 0;
		for (int i = 0; i < K; i++)
		{
			int size;
			cin >> size;
			int* temp = new int[size];
			for (int j = 0; j < size; j++)
				cin >> temp[j];

			for (int i = 0; i < size - 1; i++)
			{
				int from = temp[i];
				int to = temp[i + 1];
				graph[from][to] = 1;
			}

			delete[] temp;
		}

		cout << "#" << tc << " ";

		for (int i = 1; i <= N; i++)
		{
			cout << find_friends(i) << " ";
			visited[i] = true;
			find_longest_path(i, 1);
			visited[i] = false;
		}

		cout << answer << endl;
	}
}
