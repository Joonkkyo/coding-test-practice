#include <iostream>
#include <cmath>
using namespace std;
 
int combination(int n, int r)
{
    if (n == r || r == 0)
        return 1;
    else
        return combination(n - 1, r - 1) + combination(n - 1, r);
}
 
 
bool isPrimeNum(int n) 
{
    if (n == 1) return false;
 
    for (int i = 2; i <= sqrt(n); i++) 
    {
        if (n % i == 0) 
            return false;
    }
 
    return true;
}
 
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int test_case;
    cin >> test_case;
    for (int tc = 1; tc <= test_case; tc++)
    {
        double skill_A, skill_B;
        double P_A = 0;
        double P_B = 0;
 
        cin >> skill_A >> skill_B;
        for (int i = 1; i <= 18; i++)
        {
            if (isPrimeNum(i))
            {
                P_A += combination(18, i) * pow(double(skill_A / 100), i) * pow(1 - double(skill_A / 100), 18 - i);
                P_B += combination(18, i) * pow(double(skill_B / 100), i) * pow(1 - double(skill_B / 100), 18 - i);
            }
        }
 
        double answer = P_A + P_B - P_A * P_B;
        printf("#%d %.6f\n", tc, answer);
    }
    
    return 0;
}
