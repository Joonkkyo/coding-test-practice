class Solution:
    def regionsBySlashes(self, grid: List[str]) -> int:
        n = len(grid) 
        board = [[0] * 3 * n for _ in range(3 * n)]
        visited = [[False] * 3 * n for _ in range(3 * n)]
        dy = [0, 0, 1, -1]
        dx = [-1, 1, 0, 0]
        answer = 0
    
        def dfs(y, x):
            visited[y][x] = True
            for i in range(4):
                ny = y + dy[i]
                nx = x + dx[i]
                if 0 <= ny < 3 * n and 0 <= nx < 3 * n and not visited[ny][nx] and board[ny][nx] == 0:
                    visited[ny][nx] = True
                    dfs(ny, nx)
            
            
        for i in range(n):
            for j in range(n):
                if grid[i][j] == '/':
                    board[i * 3][j * 3 + 2] = 1
                    board[i * 3 + 1][j * 3 + 1] = 1
                    board[i * 3 + 2][j * 3] = 1
        
                if grid[i][j] == '\\':
                    board[i * 3][j * 3] = 1
                    board[i * 3 + 1][j * 3 + 1] = 1
                    board[i * 3 + 2][j * 3 + 2] = 1

        for i in range(n * 3):
            for j in range(n * 3):
                if board[i][j] == 0 and not visited[i][j]:
                    dfs(i, j)
                    answer += 1
                    
        return answer
