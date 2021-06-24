class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        row, col = len(grid), len(grid[0])
        area = 0
        
        def dfs(y, x):
            if not (0 <= x < col and 0 <= y < row) or grid[y][x] == 0:
                return 0
            
            grid[y][x] = 0
            
            return dfs(y - 1, x) + dfs(y + 1, x) + dfs(y, x + 1) + dfs(y, x - 1) + 1
                
        for i in range(row):
            for j in range(col):
                if grid[i][j] == 1:
                    area = max(dfs(i, j), area)
                    
        return area
