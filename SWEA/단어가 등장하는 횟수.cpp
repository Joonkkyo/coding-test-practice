#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

string B, S;

vector<int> getMatchTable(const string& str)
{
    int size = str.size();
    vector<int> pi(size, 0);
    int begin = 1, matched = 0;
    while (begin + matched < size)
    {
        if (str[begin + matched] == str[matched])
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

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {
        cin >> B >> S;
        vector<int> pi = getMatchTable(S);
        int idx = 0, answer = 0;

        for (int i = 0; B[i]; ++i)
        {
            while (idx > 0 && B[i] != S[idx]) idx = pi[idx - 1];
            if (B[i] == S[idx])
            {
                if (idx == S.size() - 1)
                {
                    cout << idx << endl;
                    answer++;
                    idx = pi[idx];
                }
                else idx++;
            }
        }

        cout << "#" << tc << " " << answer << "\n";
    }

    return 0;
}
