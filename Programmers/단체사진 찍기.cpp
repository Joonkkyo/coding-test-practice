#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int countDistance(char a, char b, vector<char>& vec);
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) 
{
    vector<char> character = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
    int criterion, answer = 0;
    char first, second, op;
    string str;
    bool flag = true;

    do 
    {
        flag = true;
        
        for (string cond : data)
        {
            first = cond[0];
            second = cond[2];
            op = cond[3];
            criterion = cond[4] - '0';
  
            if (op == '=')
            {
                if (countDistance(first, second, character) != criterion)
                    flag = false;
            }
            else if (op == '>')
            {
                if (countDistance(first, second, character) <= criterion)
                    flag = false;
            }
            else
            {
                if (countDistance(first, second, character) >= criterion)
                    flag = false;
            }
        }
        if (flag) answer++;
    } while (next_permutation(character.begin(), character.end()));
    
    return answer;
}

int countDistance(char a, char b, vector<char>& vec)
{
    int idx_a, idx_b;
    
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == a) idx_a = i;
        if (vec[i] == b) idx_b = i;
    }
    
    return abs(idx_a - idx_b) - 1;
}
