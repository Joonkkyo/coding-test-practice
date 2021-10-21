import sys

sys.setrecursionlimit(10**6)
M, N, K = map(int, input().split())
board = [[0] * N for _ in range(M)]
visited = [[False] * N for _ in range(M)]
answer = []
dy = [0, 0, -1, 1]
dx = [1, -1, 0, 0]
cnt = 0

for i in range(K):
    x1, y1, x2, y2 = map(int, input().split())
    for i in range(y1, y2):
        for j in range(x1, x2):
            board[i][j] = 1

def dfs(y, x):
    global cnt
    visited[y][x] = True
    cnt += 1
    
    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
        if not (0 <= ny < M and 0 <= nx < N) or visited[ny][nx]:
            continue
        
        if board[ny][nx] == 0 and not visited[ny][nx]:
            dfs(ny, nx)
         
for i in range(M):
    for j in range(N):
        if board[i][j] == 0 and not visited[i][j]:
            cnt = 0
            dfs(i, j)
            answer.append(cnt)
            
answer.sort()
print(len(answer))
for num in answer:
    print(num, end=" ")
