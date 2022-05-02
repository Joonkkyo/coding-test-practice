import sys
sys.setrecursionlimit(10**9)

def solution(n, m, image):
    def dfs(y, x):
        visited[y][x] = True
        color = image[y][x]
        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]
            if 0 <= ny < n and 0 <= nx < m and not visited[ny][nx]:
                if color == image[ny][nx]:
                    visited[ny][nx] = True
                    dfs(ny, nx)
                    
        
    visited = [[False] * m for _ in range(n)] 
    dy = [-1, 1, 0, 0]
    dx = [0, 0, -1, 1]
    answer = 0
    for i in range(n):
        for j in range(m):
            if not visited[i][j]:
                dfs(i, j)
                answer += 1
                
    return answer
