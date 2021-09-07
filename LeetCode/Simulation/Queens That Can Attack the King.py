class Solution:
    def queensAttacktheKing(self, queens: List[List[int]], king: List[int]) -> List[List[int]]:
        answer = []
        board = [[0 for _ in range(8)] for _ in range(8)]
        
        for i in range(len(queens)):
            board[queens[i][0]][queens[i][1]] = 1
            
        dy = [-1, -1, 0, 1, 1, 1, 0, -1] 
        dx = [0, -1, -1, -1, 0, 1, 1, 1]

        for i in range(8):
            y, x = king[0], king[1]
            for j in range(8):
                next_y = y + dy[i]
                next_x = x + dx[i]
                
                if 0 <= next_y < 8 and 0 <= next_x < 8:
                    y = next_y
                    x = next_x
                
                    if board[next_y][next_x] == 1:
                        answer.append([next_y, next_x])
                        break
                else:
                    break
                    
        return answer
