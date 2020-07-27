class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int M = matrix.size(); // 행
        int N = matrix[0].size(); // 
        int idx;

        if (M == 1 || N == 1)
            return true;

        for (int i = 0; i < M - 1; i++)
        {
            for (int j = 0; j < N - 1; j++)
            {
                if (matrix[i][j] != matrix[i + 1][j + 1])
                    return false;
            }
        }

        return true;
    }
};
