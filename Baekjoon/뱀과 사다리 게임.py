from collections import deque, defaultdict
import sys

def dfs():
    queue = deque()
    queue.append((1, 0))
    visited[1] = True
    while queue:
        x, cnt = queue.popleft()
        if x == 100:
            print(cnt)
            return
        
        for nx in (x + 1, x + 2, x + 3, x + 4, x + 5, x + 6):
            if not visited[nx]: 
                if nx in ladders.keys():
                    queue.append((ladders[nx], cnt + 1))
                    visited[nx], visited[ladders[nx]] = True, True
                    continue
                
                if nx in snakes.keys():
                    queue.append((snakes[nx], cnt + 1))
                    visited[nx], visited[snakes[nx]] = True, True
                    continue
                
                queue.append((nx, cnt + 1))
                visited[nx] = True


N, M = map(int, input().split())
ladders, snakes = defaultdict(int), defaultdict(int)
visited = [False] * 200

for _ in range(N):
    y, x = map(int, sys.stdin.readline().split())
    ladders[y] = x
    
for _ in range(M):
    u, v = map(int, sys.stdin.readline().split())
    snakes[u] = v
    
dfs()
