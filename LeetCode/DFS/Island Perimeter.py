class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        col, row = len(grid), len(grid[0])
        answer = 0
        
        def countPerimeter(grid: List[List[int]], i: int, j: int) -> int:
            count = 0
            if (j + 1 < row and grid[i][j + 1] == 0) or j + 1 == row: count += 1
            if (j - 1 >= 0 and grid[i][j - 1] == 0) or j == 0: count += 1
            if (i - 1 >= 0 and grid[i - 1][j] == 0) or i == 0: count += 1
            if (i + 1 < col and grid[i + 1][j] == 0) or i + 1 == col: count += 1
            return count
        
        for i in range(col):
            for j in range(row):
                if grid[i][j] == 1:
                    answer += countPerimeter(grid, i, j)
        
        return answer
