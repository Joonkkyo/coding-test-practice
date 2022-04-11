import sys

N = int(input())
board = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]
answer_list = [0, 0, 0]

def solve(y, x, n):
    val = board[y][x]
    for i in range(y, y + n):
        for j in range(x, x + n):
            if board[i][j] != val:
                solve(y, x, n // 3)
                solve(y, x + n // 3, n // 3)
                solve(y, x + n // 3 * 2, n // 3)
                solve(y + n // 3, x, n // 3)
                solve(y + n // 3, x + n // 3, n // 3)
                solve(y + n // 3, x + n // 3 * 2, n // 3)
                solve(y + n // 3 * 2, x, n // 3)
                solve(y + n // 3 * 2, x + n // 3, n // 3)
                solve(y + n // 3 * 2, x + n // 3 * 2, n // 3)
                return
        
    if val == -1: answer_list[0] += 1
    elif val == 0: answer_list[1] += 1
    else: answer_list[2] += 1     
    
solve(0, 0, N)
for answer in answer_list: 
    print(answer)
