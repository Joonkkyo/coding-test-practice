from collections import deque
import sys

R, C, N = map(int, input().split())
board = [list(input()) for _ in range(R)]
bombs = deque()

def findBomb():
    for i in range(R):
        for j in range(C):
            if board[i][j] == 'O':
                bombs.append((i, j))
                

def setBomb():
    for i in range(R):
        for j in range(C):
            if board[i][j] == '.':
                board[i][j] = 'O'

def explode():
    dy = [-1, 1, 0, 0]
    dx = [0, 0, -1, 1]
    while bombs:
        y, x = bombs.popleft()
        board[y][x] = '.'
        for i in range(4): 
            ny = y + dy[i]
            nx = x + dx[i]
            if 0 <= ny < R and 0 <= nx < C:
                if board[ny][nx] == 'O':
                    board[ny][nx] = '.'

N -= 1
while N:
    findBomb()
    setBomb()
    N -= 1
    if N == 0:
        break
    explode()
    N -= 1
    
for i in range(R):
    for j in range(C):
        print(board[i][j], end='')
    print()
                
