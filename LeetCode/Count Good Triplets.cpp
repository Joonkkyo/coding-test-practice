class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int size = arr.size();
        int answer = 0;
        for (int i = 0; i < size - 2; i++)
        {
            for (int j = i + 1; j < size - 1; j++)
            {
                if (abs(arr[i] - arr[j]) <= a)
                {
                    for (int k = j + 1; k < size; k++)
                    {
                        if (abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c)
                            answer += 1;
                    }
                }
                else
                    continue;
            }
        }
        return answer;
    }
};