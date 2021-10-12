N, M = map(int, input().split())
board = []
queue = []

dy = [0, 0, 1, -1]
dx = [1, -1, 0, 0]

for i in range(N):
    board.append(list(map(int, input())))

def bfs(y, x):    
    queue.append((y, x))

    while queue:
        y, x = queue.pop(0)

        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]
    
            if not (0 <= ny < N and 0 <= nx < M) or board[ny][nx] == 0:
                continue
                
            if board[ny][nx] == 1:
                board[ny][nx] = board[y][x] + 1
                queue.append((ny, nx))
    
    return board[N - 1][M - 1]

print(bfs(0, 0))
