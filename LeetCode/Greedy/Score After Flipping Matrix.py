class Solution:
    def matrixScore(self, grid: List[List[int]]) -> int:
        row, col = len(grid), len(grid[0])
        answer = 0
        
        for i in range(row):
            if grid[i][0] == 0:
                for j in range(col):
                    grid[i][j] ^= 1
        
        for i in range(col):
            if sum(list(zip(*grid))[i]) <= row // 2:
                for j in range(row):
                    grid[j][i] ^= 1
                    
        for i in range(row):
            bin_str = ""
            for j in range(col):
                bin_str += str(grid[i][j])
            answer += int(bin_str, 2)
                
        return answer
