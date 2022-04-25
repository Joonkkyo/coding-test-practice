from collections import deque

def move(y, x, dy, dx):
    cnt = 0
    while board[y + dy][x + dx] != '#' and board[y][x] != 'O':
        y += dy
        x += dx
        cnt += 1
    return y, x, cnt
        
        
def dfs():
    while queue:
        r_y, r_x, b_y, b_x, cnt = queue.popleft()
        if cnt > 10:
            print(-1)
            return
        
        for i in range(4):
            r_ny, r_nx, r_c = move(r_y, r_x, dy[i], dx[i])
            b_ny, b_nx, b_c = move(b_y, b_x, dy[i], dx[i])
            
            if board[b_ny][b_nx] != 'O':
                if board[r_ny][r_nx] == 'O':
                    print(cnt)
                    return    
            
                if r_ny == b_ny and r_nx == b_nx:
                    if r_c > b_c:
                        r_ny -= dy[i]
                        r_nx -= dx[i]
                        
                    else:
                        b_ny -= dy[i]
                        b_nx -= dx[i]
                    
                if not visited[r_ny][r_nx][b_ny][b_nx]:
                    visited[r_ny][r_nx][b_ny][b_nx] = True
                    queue.append((r_ny, r_nx, b_ny, b_nx, cnt + 1))
    
    print(-1)
                    
N, M = map(int, input().split())
board = [list(input()) for _ in range(N)]
visited = [[[[False] * M for _ in range(N)] for _ in range(M)] for _ in range(N)]
b_y, b_x = 0, 0
r_y, r_x = 0, 0
dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]
queue = deque()

for i in range(N):
    for j in range(M):
        if board[i][j] == 'B':
            b_y, b_x = i, j
        if board[i][j] == 'R':
            r_y, r_x = i, j
            
queue.append((r_y, r_x, b_y, b_x, 1))
visited[r_y][r_x][b_y][b_x] = True   
dfs()
