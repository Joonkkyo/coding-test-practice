class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        int answer = 0;
        vector<vector<int>> arr;
        arr.assign(n, vector<int>(m, 0));

        for (int i = 0; i < indices.size(); i++)
        {
            for (int j = 0; j < m; j++)
                arr[indices[i][0]][j] += 1;

            for (int k = 0; k < n; k++)
                arr[k][indices[i][1]] += 1;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (arr[i][j] % 2 == 1)
                    answer++;
            }
        }
        return answer;
    }
};