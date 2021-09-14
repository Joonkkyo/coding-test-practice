class Solution:
    def maxIncreaseKeepingSkyline(self, grid: List[List[int]]) -> int:
        n = len(grid)
        max_row, max_col = [0] * n, [0] * n
        answer = 0
        
        for i in range(n):
            for j in range(n):
                max_row[i] = max(max_row[i], grid[i][j])
                max_col[j] = max(max_col[j], grid[i][j])

        for i in range(n):
            for j in range(n):
                criterion = min(max_row[i], max_col[j])
                
                if grid[i][j] < criterion:
                    answer += criterion - grid[i][j]
        
        return answer
