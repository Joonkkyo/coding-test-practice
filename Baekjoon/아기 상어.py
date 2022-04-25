from collections import deque

def bfs(y, x, size):
    visited = [[False] * N for _ in range(N)]
    dist = [[0] * N for _ in range(N)] 
    fishes = []
    visited[y][x] = True
    board[y][x] = 0
    queue.append((y, x))
    while queue:
        y, x = queue.popleft()
        for i in range(4):
            ny = dy[i] + y
            nx = dx[i] + x
            if 0 <= ny < N and 0 <= nx < N and not visited[ny][nx]:
                if board[ny][nx] <= size:
                    queue.append((ny, nx))
                    visited[ny][nx] = True
                    dist[ny][nx] = dist[y][x] + 1
                    
                    if board[ny][nx] != 0 and board[ny][nx] < size:
                        fishes.append((ny, nx, dist[ny][nx]))
                        
    fishes.sort(key=lambda x: (-x[2], -x[0], -x[1]))
    return fishes
     
            
N = int(input())
board = [list(map(int, input().split())) for _ in range(N)]
queue = deque()
dy = [1, -1, 0, 0]
dx = [0, 0, 1, -1]
size, eat = 2, 0
y, x = 0, 0 
answer = 0

for i in range(N):
    for j in range(N):
        if board[i][j] == 9:
            y, x = i, j
            break
    
while True:
    fish_arr = bfs(y, x, size)
    if len(fish_arr) == 0:
        break
    
    ny, nx, dist = fish_arr.pop()
    answer += dist
    board[ny][nx] = 0
    y, x = ny, nx
    eat += 1
    if eat == size:
        eat = 0
        size += 1
        
print(answer)
