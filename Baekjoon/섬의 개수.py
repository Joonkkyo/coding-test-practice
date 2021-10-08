import sys
sys.setrecursionlimit(100000)

while True:
    w, h = map(int, input().split())
    if w == 0 and h == 0:   
        break
    
    visited = [[False] * w for _ in range(h)]
    board = []
    dy = [1, -1, 0, 0, 1, 1, -1, -1]
    dx = [0, 0, 1, -1, -1, 1, -1, 1]
    
    def dfs(y, x):
        if not (0 <= y < h and 0 <= x < w) or visited[y][x] or board[y][x] == 0:
            return
        
        visited[y][x] = True
        for i in range(8):
            dfs(y + dy[i], x + dx[i])
    
    for _ in range(h):
        board.append(list(map(int, sys.stdin.readline().split())))
    
    answer = 0
    for i in range(h):
        for j in range(w):
            if not visited[i][j] and board[i][j] == 1:
                dfs(i, j)
                answer += 1
            
    print(answer)
