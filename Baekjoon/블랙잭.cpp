#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    int N, M; // N : 카드 수, M : 최대의 합
    int num;
    int max = 0;
    vector<int> vec;

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> num;
        vec.push_back(num);
    }

    for (int i = 0; i < N - 2; i++)
    {
        for (int j = i + 1; j < N - 1; j++)
        {
            for (int k = j + 1; k < N; k++)
            {
                if (vec[i] + vec[j] + vec[k] <= M && vec[i] + vec[j] + vec[k] > max)
                    max = vec[i] + vec[j] + vec[k];
            }
        }
    }
    cout << max << endl;
}