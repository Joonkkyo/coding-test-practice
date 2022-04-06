from collections import deque
import sys

def bfs():
    while queue:
        y, x = queue.popleft()
        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]
            if 0 <= ny < N and 0 <= nx < M and board[ny][nx] == 0:
                board[ny][nx] = board[y][x] + 1        
                queue.append([ny, nx])
                
                
M, N = map(int, input().split())
board = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]
visited = [[False] * M for _ in range(N)]
dy = [1, -1, 0, 0]
dx = [0, 0, -1, 1]
queue = deque([])
answer = 0
        
for i in range(N):
    for j in range(M):
        if board[i][j] == 1:
            queue.append([i, j])   
            
bfs()
flag = False
for i in range(N):
    for j in range(M):
        if board[i][j] == 0:
            flag = True
            break
        answer = max(answer, board[i][j])
        
    if flag:
        break

if flag: print(-1)
else: print(answer - 1)
