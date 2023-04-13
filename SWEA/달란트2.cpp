#include <iostream>
#include <vector>
using namespace std;
 
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
     
    int test_case;
    cin >> test_case;
    for (int tc = 1; tc <= test_case; tc++)
    {
        int N, P;
        int q, r; // 몫, 나머지
        long long answer = 1;
        cin >> N >> P;
        q = N / P;
        r = N % P;
 
        vector<int> v(P, q);
        for (register int i = 0; i < r; i++)
            v[i]++;
 
        for (auto num : v)
            answer *= num;
         
        cout << "#" << tc << " " << answer << '\n';
    }
 
    return 0;
}
