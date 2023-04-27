#include <iostream>
#include <vector>
#include <string>
using namespace std;

string T, P;

vector<int> getMatchTable(const string& pattern)
{
    int size = pattern.size();
    vector<int> pi(size, 0);
    int begin = 1, matched = 0;
    while (begin + matched < size)
    {
        if (pattern[begin + matched] == pattern[matched])
        {
            ++matched;
            pi[begin + matched - 1] = matched;
        }

        else
        {
            if (matched == 0) ++begin;
            else
            {
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }

    return pi;
}

void KMP(const string& parent, const string& pattern)
{
    vector<int> pi = getMatchTable(pattern);
    vector<int> v;
    int idx = 0;

    for (int i = 0; parent[i]; ++i)
    {
        while (idx > 0 && parent[i] != pattern[idx]) idx = pi[idx - 1];
        if (parent[i] == pattern[idx])
        {
            if (idx == pattern.size() - 1)
            {
                v.push_back(i - pattern.size() + 2);
                idx = pi[idx];
            }
            else idx++;
        }
    }
    
    cout << v.size() << '\n';
    for (int num : v) cout << num << " ";
    cout << '\n';
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    getline(cin, T);
    getline(cin, P);

    KMP(T, P);

    return 0;
}
