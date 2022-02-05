from collections import deque

N = int(input())
dy = [-2, -1, 1, 2, 2, 1, -1, -2]
dx = [-1, -2, -2, -1, 1, 2, 2, 1]

for i in range(N):
    l = int(input())
    y, x = map(int, input().split())
    target_y, target_x = map(int, input().split())
    board = [[0] * l for _ in range(l)]
    queue = deque()
    queue.append((y, x))
    
    while queue:
        y, x = queue.popleft()
        if y == target_y and x == target_x:
            break
        
        for i in range(8):
            ny = y + dy[i]
            nx = x + dx[i]
            if 0 <= ny < l and 0 <= nx < l:
                if board[ny][nx] == 0:
                    board[ny][nx] = board[y][x] + 1
                    queue.append((ny, nx))
                    
    print(board[target_y][target_x])
