from collections import deque
import sys


def bfs(y, x):
    global area
    visited[y][x] = True
    queue.append((y, x))
    
    while queue:
        y, x = queue.popleft()
        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]
            if 0 <= ny < n and 0 <= nx < m and board[ny][nx] == 1:
                if not visited[ny][nx]:
                    area += 1
                    visited[ny][nx] = True
                    queue.append((ny, nx))
                    
    return area


n, m = map(int, input().split())
board = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
visited = [[False] * m for _ in range(n)]
dy = [0, 0, 1, -1]
dx = [1, -1, 0, 0]
answer, count = 0, 0
queue = deque()

for i in range(n):
    for j in range(m):
        if not visited[i][j] and board[i][j] == 1:
            area = 1
            answer = max(answer, bfs(i, j))
            count += 1

print(count)
print(answer)
