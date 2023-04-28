#include <iostream>
#include <cstring>
using namespace std;

constexpr int MAX = 200001;
int arr[MAX], dp[MAX];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc)
    {
        int N;
        cin >> N;

        for (register int i = 1; i <= N; i++)
            cin >> arr[i];

        int maxSum = -1e9;
        for (int i = 1; i <= N; i++)
        {
            dp[i] = max(dp[i - 1], 0) + arr[i];
            maxSum = max(maxSum, dp[i]);
        }
       
        cout << maxSum << '\n';
    }

    return 0;
}
