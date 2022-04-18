import sys

N = int(input())
board = [list(sys.stdin.readline().rstrip()) for _ in range(N)]

r_cnt, c_cnt = 0, 0
for i in range(N):
    count = 0
    for j in range(N):
        if board[i][j] == '.':
            count += 1
        if board[i][j] == 'X' or j == N - 1:
            if count >= 2:
                r_cnt += 1
            count = 0
            
for j in range(N):
    for i in range(N):
        if board[i][j] == '.':
            count += 1
        if board[i][j] == 'X' or i == N - 1:
            if count >= 2:
                c_cnt += 1
            count = 0
            
print(r_cnt, c_cnt)
