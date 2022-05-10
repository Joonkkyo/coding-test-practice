from collections import deque


def bfs(r, c, n):
    visited = [[False] * N for _ in range(N)]
    queue = deque([(r, c, 0)])
    visited[r][c] = True
    
    while queue:
        y, x, cnt = queue.popleft()
        if y == r2 and x == c2:
            return cnt
        
        for dy, dx in directions:
            ny = y + dy
            nx = x + dx
            if 0 <= ny < N and 0 <= nx < N and not visited[ny][nx]:
                visited[ny][nx] = True
                queue.append((ny, nx, cnt + 1))
            
    else:
        return -1
    
    
N = int(input())
r1, c1, r2, c2 = map(int, input().split())
directions = [(-2, -1), (-2, 1), (0, -2), (0, 2), (2, -1), (2, 1)]
print(bfs(r1, c1, 0))
