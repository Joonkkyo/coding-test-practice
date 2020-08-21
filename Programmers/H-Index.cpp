#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int tmp = 0;
    int count = 0;
    int size = citations.size();
    sort(citations.begin(), citations.end());
    if (citations[0] >= size)
        return size;

    for (int i = 0; i < size; i++)
    {
        tmp = citations[i];
        if (tmp <= size - i)
        {
            if (tmp >= answer)
                answer = tmp;
        }
        else
            count++;
    }

    if (count > answer)
        answer = count;

    return answer;
}