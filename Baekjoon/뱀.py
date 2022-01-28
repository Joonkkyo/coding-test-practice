from collections import deque
import sys


def change_dir(d, c):
    if c == 'L':
        d = (d - 1) % 4
    else:
        d = (d + 1) % 4
    return d

N = int(input())
board = [[0] * N for _ in range(N)]

K = int(input())
for _ in range(K):
    apple_y, apple_x = map(int, sys.stdin.readline().split())
    board[apple_y - 1][apple_x - 1] = 'A'

snake_pos = deque()
snake_pos.append((0, 0))
board[0][0] = 'B'

L = int(input())
L_dic = {}
for _ in range(L):
    X, C = sys.stdin.readline().split()
    L_dic[int(X)] = C

dy = [0, 1, 0, -1]
dx = [1, 0, -1, 0]
dir, time = 0, 0
y, x = 0, 0

while(True):
    ny = y + dy[dir]
    nx = x + dx[dir]
    
    if 0 <= ny < N and 0 <= nx < N:
        time += 1
        if board[ny][nx] == 'A': ## 사과 있는 경우
            snake_pos.append((ny, nx))
            board[ny][nx] = 'B'
            y, x = ny, nx
            
        elif board[ny][nx] == 0: 
            snake_pos.append((ny, nx))
            board[ny][nx] = 'B'
            tail_y, tail_x = snake_pos.popleft()
            board[tail_y][tail_x] = 0
            y, x = ny, nx
            
        else:  ## 몸과 충돌
            break
        
        if time in L_dic.keys():
            dir = change_dir(dir, L_dic[time])
        
    else:
        time += 1
        break

print(time)
