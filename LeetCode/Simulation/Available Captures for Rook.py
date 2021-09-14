class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        answer = 0
        rook_y, rook_x = 0, 0
        dy = [-1, 0, 1, 0]
        dx = [0, -1, 0, 1]
        
        for i in range(8):
            for j in range(8):
                if 'R' == board[i][j]:
                    rook_y = i
                    rook_x = j
                    break
        
        for i in range(4):
            y, x = rook_y, rook_x
            for _ in range(7):
                next_y = y + dy[i]
                next_x = x + dx[i]
                
                if 0 <= next_y < 8 and 0 <= next_x < 8:
                    if board[next_y][next_x]  == 'p':
                        answer += 1
                        break
                    elif board[next_y][next_x] == 'B':
                        break
                    else:
                        y = next_y
                        x = next_x
                        continue
                        
        return answer
            
        
