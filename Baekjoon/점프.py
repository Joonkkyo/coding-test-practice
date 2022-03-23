import sys

N = int(input())
board = []
dp = [[0] * N for _ in range(N)]
for _ in range(N):
    board.append(list(map(int, sys.stdin.readline().split())))

dp[0][0] = 1
for i in range(N):
    for j in range(N):
        if i == N - 1 and j == N - 1:
            break
        
        ny = i + board[i][j]
        nx = j + board[i][j]
        
        if ny < N:
            dp[ny][j] += dp[i][j]
        
        if nx < N:
            dp[i][nx] += dp[i][j]
            
print(dp[N - 1][N - 1])
