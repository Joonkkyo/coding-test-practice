#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    int r_temp = 0;
    while (n > 0)
    {
        r_temp = n % 3;
        n = n / 3;

        if (r_temp == 0)
        {
            n -= 1;
            r_temp = 4;
        }
        answer = to_string(r_temp) + answer;
    }
    return answer;
}