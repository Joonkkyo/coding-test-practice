import sys 

N, M, y, x, K = map(int, sys.stdin.readline().split())
board = []

for _ in range(N):
    pos = list(map(int, sys.stdin.readline().split()))
    board.append(pos)
    
command = list(map(int, input().split()))

dy = [0, 0, -1, 1]
dx = [1, -1, 0, 0]

dice = [0, 0, 0, 0, 0, 0]
for i in range(K):
    ny = y + dy[command[i] - 1]
    nx = x + dx[command[i] - 1]
    
    if 0 <= ny < N and 0 <= nx < M:
        if command[i] == 1:
            dice[0], dice[2], dice[3], dice[5] = dice[3], dice[0], dice[5], dice[2]
        elif command[i] == 2:
            dice[0], dice[2], dice[3], dice[5] = dice[2], dice[5], dice[0], dice[3]
        elif command[i] == 3:
            dice[0], dice[1], dice[4], dice[5] = dice[4], dice[0], dice[5], dice[1]
        else:
            dice[0], dice[1], dice[4], dice[5] = dice[1], dice[5], dice[0], dice[4]
            
        if board[ny][nx] == 0:
            board[ny][nx] = dice[5]
        else:
            dice[5] = board[ny][nx]
            board[ny][nx] = 0
            
        y, x = ny, nx
    
    else:
        continue
    
    print(dice[0])
