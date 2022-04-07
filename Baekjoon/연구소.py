from itertools import combinations
from collections import deque
import copy
import sys


def bfs():
    while queue:
        y, x = queue.popleft()
        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]
            if 0 <= ny < N and 0 <= nx < M and lab[ny][nx] == 0:
                lab[ny][nx] = 2
                queue.append((ny, nx))
                
        
N, M = map(int, input().split())
board = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]
idx_list = []
dy = [0, 0, 1, -1]
dx = [1, -1, 0, 0]
answer = 0 

for i in range(N):
    for j in range(M):
        if board[i][j] == 0:
            idx_list.append((i, j))

for idx in combinations(idx_list, 3):
    area = 0
    lab = copy.deepcopy(board)
    queue = deque([])
    for i in range(N):
        for j in range(M):        
            if (i, j) in idx:
                lab[i][j] = 1
                
            if lab[i][j] == 2:
                queue.append((i, j))    
    bfs()
    for k in lab:
        area += k.count(0)
    answer = max(answer, area)
    
print(answer)
