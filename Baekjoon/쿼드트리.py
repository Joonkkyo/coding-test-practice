import sys

N = int(input())
board = [list(sys.stdin.readline()) for _ in range(N)]
answer = ""

def solve(y, x, n):
    global answer
    color = board[y][x]
    for i in range(y, y + n):
        for j in range(x, x + n):
            if color != board[i][j]:
                answer += '('
                solve(y, x, n // 2)
                solve(y, x + n // 2, n // 2)
                solve(y + n // 2, x, n // 2)
                solve(y + n // 2, x + n // 2, n // 2)
                answer += ')'
                return
            
    answer += color
    
    
solve(0, 0, N)    
print(answer)
