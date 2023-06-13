#include <iostream>
#include <queue>
#include <vector>
#define rint register int
#define pii pair<int, int> 
using namespace std;

constexpr int MAX_N = 100001;
int visited[MAX_N];
const int dx[2] = { -1, 1 };

bool isValid(int pos)
{
	return 0 <= pos && pos <= MAX_N;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
 
	int N, K;
	cin >> N >> K;
	priority_queue<pii, vector<pii>, greater<pii>> pq; // min heap
	pq.push({ 0, N });

	while (!pq.empty())
	{
		int time = pq.top().first;
		int x = pq.top().second;
		pq.pop();
		
		if (x == K)
		{
			cout << time << endl;
			break;
		}

        if (isValid(x * 2) && !visited[x * 2])
		{
			pq.push({ time, x * 2 });
			visited[x * 2] = true;
		}
        
		for (rint i = 0; i < 2; ++i)
		{
			int nx = x + dx[i];
			if (isValid(nx) && !visited[nx])
			{
				pq.push({ time + 1, nx});
				visited[nx] = true;
			}
		}
	}
	
	return 0;
}
