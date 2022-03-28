class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        dp = [[1] * i for i in range(1, rowIndex + 2)]
        for i in range(len(dp)):
            for j in range(len(dp[i])):
                if j == 0 or j == len(dp[i]) - 1:
                    continue  
                else:
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]
                    
        return dp[rowIndex]                 
