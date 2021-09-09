class Solution:
    def tictactoe(self, moves: List[List[int]]) -> str:
        def isFinished(board):
            for i in range(3):
                if board[i][0] != ' ' and board[i][0] == board[i][1] and board[i][1] == board[i][2]: ## row
                    return True
                elif board[0][i] != ' ' and board[0][i] == board[1][i] and board[1][i] == board[2][i]: ## column
                    return True
                elif board[0][0] != ' ' and board[0][0] == board[1][1] and board[1][1] == board[2][2]: ## diagonal
                    return True
                elif board[2][0] != ' ' and board[2][0] == board[1][1] and board[1][1] == board[0][2]: ## diagonal
                    return True
            return False

        board = [[' ' for _ in range(3)] for i in range(3)]
        count = 0
        
        for i in range(len(moves)):
            if i % 2 == 0:
                board[moves[i][0]][moves[i][1]] = 'X'
            else:
                board[moves[i][0]][moves[i][1]] = 'O'
            count += 1
            
            if count >= 5:
                if isFinished(board):
                    return 'A' if i % 2 == 0 else 'B'
        
        return "Draw" if count == 9 else "Pending"
            
            
        
