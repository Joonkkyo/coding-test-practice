#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> answer_1{ 1, 2, 3, 4, 5 };
    vector<int> answer_2{ 2, 1, 2, 3, 2, 4, 2, 5 };
    vector<int> answer_3{ 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

    int score_1 = 0;
    int score_2 = 0;
    int score_3 = 0;
    int max_cnt = 0;
    int size = answers.size();

    for (int i = 0; i < size; i++)
    {
        int n1 = i % 5;
        int n2 = i % 8;
        int n3 = i % 10;

        if (answers[i] == answer_1[n1]) score_1++;
        if (answers[i] == answer_2[n2]) score_2++;
        if (answers[i] == answer_3[n3]) score_3++;
    }

    max_cnt = max(score_1, max(score_2, score_3));
    if (max_cnt == score_1) answer.push_back(1);
    if (max_cnt == score_2) answer.push_back(2);
    if (max_cnt == score_3) answer.push_back(3);
    return answer;
}