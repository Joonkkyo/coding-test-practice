from collections import deque
import sys

def dfs():
    while queue:
        z, y, x = queue.popleft()
        for i in range(6):
            nx = x + dx[i]
            ny = y + dy[i]
            nz = z + dz[i]
            if 0 <= nx < M and 0 <= ny < N and 0 <= nz < H and board[nz][ny][nx] == 0:
                board[nz][ny][nx] = board[z][y][x] + 1
                queue.append((nz, ny, nx))


M, N, H = map(int, input().split())
board = [[list(map(int, sys.stdin.readline().split())) for _ in range(N)] for _ in range(H)]
dx = [0, 0, -1, 1, 0, 0] 
dy = [0, 0, 0, 0, 1, -1]
dz = [1, -1, 0, 0, 0, 0]
queue = deque()
answer = 0

for i in range(H):
    for j in range(N):
        for k in range(M):
            if board[i][j][k] == 1:
                queue.append((i, j, k))
                
dfs()     
for i in range(H):
    for j in range(N):
        for k in range(M):
            if board[i][j][k] == 0: 
                print(-1)
                exit(0)
        answer = max(answer, max(board[i][j]))    
        
print(answer - 1)
