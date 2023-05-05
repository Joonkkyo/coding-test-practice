#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

constexpr int INF = 1e9;
constexpr int MAX = 501;
int graph[MAX][MAX];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
    int T;
    cin >> T;
    for (register int tc = 1; tc <= T; ++tc)
    {
        int N, M;
        cin >> N >> M;
        for (register int i = 1; i <= N; ++i)
            for (register int j = 1; j <= N; ++j)
                if (i == j) graph[i][j] = 0;
                else graph[i][j] = INF;

        while (M--)
        {
            int a, b, c;
            cin >> a >> b >> c;
            if (graph[a][b] > c) graph[a][b] = c;
        }

        for (register int k = 1; k <= N; ++k)
            for (register int i = 1; i <= N; ++i)
                for (register int j = 1; j <= N; ++j)
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);

        cout << '#' << tc << " ";
        for (register int i = 1; i <= N; ++i)
        {
            for (register int j = 1; j <= N; ++j)
                if (graph[i][j] == INF) cout << -1 << " ";
                else cout << graph[i][j] << " ";
        }
      
        cout << '\n';
    }

    return 0;
}
