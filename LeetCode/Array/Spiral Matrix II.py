class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        row_start, col_start = 0, 0
        row_end, col_end = n - 1, n - 1
        answer = [[0 for _ in range(n)] for _ in range(n)]
        num = 1
        
        while True:
            for i in range(col_start, col_end + 1):
                answer[row_start][i] = num
                num += 1
            row_start += 1
            
            if num > n*n:
                break
                
            for i in range(row_start, row_end + 1):
                answer[i][col_end] = num
                num += 1
            col_end -= 1
            
            if num > n*n:
                break
                
            for i in range(col_end, col_start - 1, -1):
                answer[row_end][i] = num
                num += 1
            row_end -= 1
            
            if num > n*n:
                break
                
            for i in range(row_end, row_start - 1, -1):
                answer[i][col_start] = num
                num += 1
            col_start += 1
            
            if num > n*n:
                break
            
        return answer
