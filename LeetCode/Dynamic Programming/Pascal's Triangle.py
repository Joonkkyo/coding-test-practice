class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        dp = [[1] * (i + 1) for i in range(numRows)]
        for i in range(numRows):
            for j in range(i):
                if j == 0 or j == numRows:
                    continue
                else:
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]
                    
        return dp
