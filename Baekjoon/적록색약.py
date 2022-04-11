import sys

sys.setrecursionlimit(10**9)
N = int(input())
board = [list(sys.stdin.readline().strip()) for _ in range(N)]
visited = [[False] * N for _ in range(N)]
dy = [0, 0, -1, 1]
dx = [1, -1, 0, 0]

def dfs(y, x, color):
    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
        if 0 <= ny < N and 0 <= nx < N and not visited[ny][nx] and board[ny][nx] == color:
            visited[ny][nx] = True
            dfs(ny, nx, color)
            
            
ans_1, ans_2 = 0, 0
for i in range(N):
    for j in range(N):
        if not visited[i][j]:
            dfs(i, j, board[i][j])
            ans_1 += 1

for i in range(N):
    for j in range(N):
        if board[i][j] == 'G':
            board[i][j] = 'R'
 
visited = [[False] * N for _ in range(N)]           
for i in range(N):
    for j in range(N):
        if not visited[i][j]:
            dfs(i, j, board[i][j])
            ans_2 += 1

print(ans_1, ans_2)
