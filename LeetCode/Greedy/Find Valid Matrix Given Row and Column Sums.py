class Solution:
    def restoreMatrix(self, rowSum: List[int], colSum: List[int]) -> List[List[int]]:
        row = len(rowSum)
        col = len(colSum)
        total = sum(rowSum)
        answer = [[0 for _ in range(col)] for _ in range(row)]
        
        for i in range(row):
            for j in range(col):
                if rowSum[i] * colSum[j] == 0:
                    answer[i][j] = 0                     
                else:
                    temp = min(rowSum[i], colSum[j])
                    answer[i][j] = temp
                    rowSum[i] -= temp
                    colSum[j] -= temp
    
        return answer
