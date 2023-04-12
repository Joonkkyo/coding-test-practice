#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
 
string pattern[10] = { "0001101", "0011001", "0010011", "0111101", "0100011", "0110001", "0101111", "0111011", "0110111", "0001011" };
 
bool isValidPattern(string s)
{
    for (int i = 0; i < 10; i++)
    {
        if (s.compare(pattern[i]) == 0)
            return true;
    }
    return false;
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
        int N, M;
        cin >> N >> M;
        vector<string> v;
 
        for (int i = 0; i < N; i++)
        {
            string input;
            cin >> input;
            v.push_back(input);
        }
 
        string password;
        bool flag = false;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M - 7; j++)
            {
                string sub = v[i].substr(j, 7);
                for (int k = 0; k < 10; k++)
                {
                    if (sub.compare(pattern[k]) == 0)
                    {
                        int count = 0;
                        password = v[i].substr(j, 56);
                        for (int i = 0; i < password.size(); i += 7)
                        {
                            string sub_password = password.substr(i, 7);
                            if (isValidPattern(sub_password)) count++;
                        }
                        if (count == 8)
                        {
                            flag = true;
                            break;
                        }
                    }
                }
                if (flag) break;
            }
        }
         
        vector<string> sub_password_vec;
        for (int i = 0; i < password.size(); i += 7)
        {
            string sub_password = password.substr(i, 7);
            sub_password_vec.push_back(sub_password);
        }
 
        vector<int> decimal_pw;
        for (auto sub_password : sub_password_vec)
        {
            for (int i = 0; i < 10; i++)
            {
                if (sub_password.compare(pattern[i]) == 0)
                    decimal_pw.push_back(i);
            }
        }
 
        int total = 0;
        int sum = 0;
        for (int i = 0; i < decimal_pw.size(); i++)
        {
            if (i % 2 != 0)
                total += decimal_pw[i];
            else
                sum += decimal_pw[i];
        }
 
        int result = sum * 3 + total;
 
        if (result % 10 == 0) cout << "#" << m << " " << accumulate(decimal_pw.begin(), decimal_pw.end(), 0) << '\n';
        else cout << "#" << tc << " " << 0 << '\n';
    }
    
    return 0;
}
