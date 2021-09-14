class Solution:
    def maxIncreaseKeepingSkyline(self, grid: List[List[int]]) -> int:
        max_row, max_col = [], []
        tmp_row, tmp_col = 0, 0
        answer = 0
        
        for i in range(len(grid)):
            tmp_row = 0
            for j in range(len(grid[0])):
                tmp_row = max(tmp_row, grid[i][j])
            max_row.append(tmp_row)
        
        for i in range(len(grid[0])):
            tmp_col = 0
            for j in range(len(grid)):
                tmp_col = max(tmp_col, grid[j][i])
            max_col.append(tmp_col)
            
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                criterion = min(max_row[i], max_col[j])
                
                if grid[i][j] < criterion:
                    answer += criterion - grid[i][j]
        
        return answer
