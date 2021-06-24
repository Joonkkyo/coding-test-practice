class Solution:
    def countBattleships(self, board: List[List[str]]) -> int:
        row, col = len(board), len(board[0])
        answer = 0
        
        def dfs(y, x):
            if not (0 <= x < col and 0 <= y < row) or board[y][x] == '.':
                return 0
            board[y][x] = '.'
            
            dfs(y - 1, x) 
            dfs(y + 1, x) 
            dfs(y, x - 1) 
            dfs(y, x + 1)
            
            return 1
        
        for i in range(row):
            for j in range(col):
                if board[i][j] == 'X':
                    answer += dfs(i, j)
            
        return answer
            
        
