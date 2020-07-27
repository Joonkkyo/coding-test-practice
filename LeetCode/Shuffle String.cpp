class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string ans;
        vector<pair<char, int>> p;
        for (int i = 0; i < s.size(); i++)
        {
            p.push_back({ s[i], indices[i] });
        }
        sort(p.begin(), p.end(), compare);

        for (auto i : p)
            ans += i.first;

        return ans;
    }

    static bool compare(pair<char, int> a, pair<char, int> b)
    {
        return a.second < b.second;
    }
};