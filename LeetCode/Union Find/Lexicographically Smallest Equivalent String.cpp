class Solution {
public:
    const static int MAX_N = 1001;
    int parent[MAX_N];
    
    void initParent() {
        for (int i = 0; i < MAX_N; ++i) parent[i] = i;
    }

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

    char numToChar(int x) {
        return 'a' + x;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        initParent(); 
        string ans = "";
        int size = s1.size();
        for (int i = 0; i < size; ++i) {
            merge(s1[i] - 'a', s2[i] - 'a');
        }

        for (int i = 0; i < baseStr.size(); ++i) {
            ans += numToChar(find(baseStr[i] - 'a'));
        }

        return ans;
    }
};
