n, m = map(int, input().split())
visit = [[0] * m for _ in range(n)]
y, x, direction = map(int, input().split())
board = []

for i in range(n):
    board.append(list(map(int, input().split())))

answer = 1
visit[y][x] = 1
dy = [-1, 0, 1, 0]  ## 북, 동, 남, 서
dx = [0, 1, 0, -1]
turn_time = 0

while True:
    direction -= 1
    if direction == -1:
        direction = 3
        
    next_y = y + dy[direction]
    next_x = x + dx[direction]
    
    if visit[next_y][next_x] == 0 and board[next_y][next_x] == 0:
        visit[next_y][next_x] = 1
        y = next_y
        x = next_x
        answer += 1
        turn_time = 0
        continue
    else:
        turn_time += 1
    
    if turn_time == 4:
        next_y = y - dy[direction]
        next_x = x - dx[direction]
        
        if board[next_y][next_x] == 0:
            y = next_y
            x = next_x
            turn_time = 0
        else:
            break

print(answer)
