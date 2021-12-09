M, N = map(int, input().split())
r, c, d = map(int, input().split())
board = []
visited = [[False] * N for _ in range(M)]
for _ in range(M):
    board.append(list(map(int, input().split())))

dy = [-1, 0, 1, 0] 
dx = [0, 1, 0, -1]

def turn_left():
    global d
    d = (d - 1) % 4

y, x = r, c
visited[y][x] = True    
answer = 1

while True: 
    blocked = True
    for i in range(4):
        turn_left()
        ny = y + dy[d]
        nx = x + dx[d]
        if 0 <= ny < M and 0 <= nx < N: 
            if board[ny][nx] == 0 and not visited[ny][nx]:
                visited[ny][nx] = True
                y, x = ny, nx
                answer += 1
                blocked = False
                break
            
    if blocked: 
        ny = y - dy[d]
        nx = x - dx[d]
        if 0 <= ny < M and 0 <= nx < N:
            if board[ny][nx] == 1:
                break
            else: 
                y, x = ny, nx
    
print(answer)
    
    
    
