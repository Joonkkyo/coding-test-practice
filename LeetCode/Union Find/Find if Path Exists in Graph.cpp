class Solution {
public:
    const static int MAX_N = 200001;
    int parent[MAX_N];

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x < y) parent[y] = x;
        else parent[x] = y; 
    }

    void initParent() {
        for (int i = 0; i < MAX_N; ++i) parent[i] = i;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        initParent();
        int size = edges.size();
        for (int i = 0; i < size; ++i) {
            merge(edges[i][0], edges[i][1]);
        }
        
        return (find(source) == find(destination)) ? true : false;
    }
};
