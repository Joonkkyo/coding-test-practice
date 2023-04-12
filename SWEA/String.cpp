#include <iostream>
#include <cstring>
using namespace std;
 
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    for (int tc = 1; tc <= 10; tc++)
    {
        int t;
        string target, str;
        cin >> t;
        cin >> target;
        cin >> str;
        int s_size = str.size();
        int t_size = target.size();
        int answer = 0;
 
        for (register int i = 0; i <= s_size - t_size; i++)
        {
            if (target.compare(str.substr(i, t_size)) == 0)
                answer++;
        }
 
        cout << "#" << tc << " " << answer << "\n";
    }
 
    return 0;
}
