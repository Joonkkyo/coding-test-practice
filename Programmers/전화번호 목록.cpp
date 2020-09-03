#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    int size = phone_book.size();
    int flag = 0;
    sort(phone_book.begin(), phone_book.end());

    for (int i = 0; i < size - 1; i++)
    {
        if (phone_book[i][0] == phone_book[i + 1][0])
        {
            if (phone_book[i].size() == 1)
                flag = 1;
            else
            {
                for (int j = 1; j < phone_book[i].size(); j++)
                {
                    if (phone_book[i][j] == phone_book[i + 1][j])
                        flag = 1;
                    else
                    {
                        flag = 0;
                        break;
                    }
                }
            }
        }

        if (flag == 1)
        {
            answer = false;
            break;
        }
    }
    return answer;
}