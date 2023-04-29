#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

typedef pair<int, pair<int, int>> pp;
typedef long long ll;
constexpr int MAX = 1000;
int arr[MAX];
vector<pp> v(MAX);

bool cmp(const pp& a, const pp& b)
{
    if (a.second.first == b.second.first) return a.second.second < b.second.second;
    return a.second.first > b.second.first;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, C;
    cin >> N >> C;
    unordered_map<int, int> m1, m2;
    for (register int i = 0; i < N; ++i)
    {
        cin >> arr[i];
        if (m1.find(arr[i]) == m1.end() && m2.find(arr[i]) == m2.end())
        {
            m1[arr[i]] = 1;
            m2[arr[i]] = i;
        }

        else m1[arr[i]]++;
    }

    for (register int i = 0; i < N; ++i)
        v.push_back({ arr[i], make_pair(m1[arr[i]], m2[arr[i]]) });

    sort(v.begin(), v.end(), cmp);

    for (register int i = 0; i < N; ++i)
        cout << v[i].first << " ";
    cout << '\n';

    return 0;
}
