class Solution:
    def updateBoard(self, board: List[List[str]], click: List[int]) -> List[List[str]]:
        row, col = len(board), len(board[0])
        cur_y, cur_x = click[0], click[1]
        temp_board = [[0 for _ in range(col)] for _ in range(row)]
        dy = [-1, -1, -1, 0, 0, 1, 1, 1]
        dx = [-1, 0, 1, -1, 1, -1, 0, 1]
        
        def addDigit(y, x):
            if not (0 <= y < row and 0 <= x < col) or board[y][x] == 'M':
                return
            
            temp_board[y][x] += 1
            return
        
        def dfs(y, x):
            if not (0 <= y < row and 0 <= x < col) or temp_board[y][x] == 'V':
                return 
            
            if temp_board[y][x] == 0:
                board[y][x] = 'B'
                temp_board[y][x] = 'V'
            else:
                board[y][x] = str(temp_board[y][x])
                return
            
            for i in range(8):
                dfs(y + dy[i], x + dx[i])
                
        if board[cur_y][cur_x] == 'M':
            board[cur_y][cur_x] = 'X'
            return board

        else:
            for i in range(row):
                for j in range(col):
                    if board[i][j] == 'M':
                        temp_board[i][j] = 'M'
                        for k in range(8):
                            addDigit(i + dy[k], j + dx[k])
            
            if temp_board[cur_y][cur_x] != 0:
                board[cur_y][cur_x] = str(temp_board[cur_y][cur_x])
                return board
            else:
                for i in range(row):
                    for j in range(col):
                        dfs(cur_y, cur_x)
                        
            return board
                   
