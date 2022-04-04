import sys

N = int(input())
board = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]
blue, white = 0, 0

def solve(y, x, n):
    global blue, white
    color = board[y][x]
    for i in range(y, y + n):
        for j in range(x, x + n):
            if color != board[i][j]:
                solve(y, x, n // 2)
                solve(y, x + n // 2, n // 2)
                solve(y + n // 2, x, n // 2)
                solve(y + n // 2, x + n // 2, n // 2)
                return
            
    if color == 0: white += 1
    else: blue += 1


solve(0, 0, N)    
print(white)
print(blue)
