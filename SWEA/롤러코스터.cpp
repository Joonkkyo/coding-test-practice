#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
constexpr int MOD = 1000000007;

bool cmp(const pair<ll, ll>& a, const pair<ll, ll>& b)
{
    return b.second * (a.first - 1) > a.second * (b.first - 1);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; ++tc)
    {
        vector<pair<int, int> > v;
        int N;
        cin >> N;
        for (register int i = 0; i < N; i++)
        {
            ll a, b;
            cin >> a >> b;
            v.push_back({ a, b });
        }

        sort(v.begin(), v.end(), cmp);
        ll answer = 1;

        for (int i = 0; i < N; ++i)
            answer = ((v[i].first * answer) % MOD + v[i].second) % MOD;
          
        cout << '#' << tc << ' ' << answer << '\n';
    }

    return 0;
}
