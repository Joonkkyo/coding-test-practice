#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;

    for (tc = 1; tc <= 10; ++tc)
    {
        int N, answer = 0;
        cin >> N;
        vector v;

        for (register int i = 0; i < N; i++)
        {
            int height;
            cin >> height;
            v.push_back(height);
        }

        for (register int i = 2; i < v.size() - 2; i++)
        {
            int l_max, r_max, total_max;

            l_max = max(v[i - 1], v[i - 2]);
            r_max = max(v[i + 1], v[i + 2]);
            total_max = max(l_max, r_max);

            if (v[i] > total_max)
                answer += v[i] - total_max;
        }
      
        cout << "#" << tc << ' ' << answer << '\n';
    }
  
    return 0;
}
