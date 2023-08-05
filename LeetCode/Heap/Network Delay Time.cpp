#define pii pair<int, int>

class Solution {
public:
    const int INF = 9999999;
    const static int MAX_N = 101;
    int dist[MAX_N];
    vector<pii> graph[MAX_N];
    
    void initDist() {
        for (int i = 0; i < MAX_N; ++i) dist[i] = INF;
    }
    
    void dijkstra(int start) {
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.emplace(0, start);
        dist[start] = 0;
        
        while (!pq.empty()) {
            int cost = pq.top().first;
            int cur = pq.top().second;
            pq.pop();
            if (dist[cur] < cost) continue;
            for (int i = 0; i < graph[cur].size(); ++i) {
                int next = graph[cur][i].first;
                int newCost = cost + graph[cur][i].second;
                if (dist[next] > newCost) {
                    dist[next] = newCost;
                    pq.emplace(newCost, next);
                }
            }
        }
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        initDist();
        for (int i = 0; i < times.size(); ++i) {
            graph[times[i][0]].push_back({times[i][1], times[i][2]});
        }

        dijkstra(k);
        int answer = 0;
        for (int i = 1; i <= n; ++i) {
            if (dist[i] == INF) return -1; 
            answer = max(answer, dist[i]);
        }

        return answer;
    }
};
