from collections import deque

N, K = map(int, input().split())
MAX = int(1e5)
queue = deque()
queue.append(N)
visited = [0] * (MAX + 1)

while queue:
    x = queue.popleft()
    if x == K:
        print(visited[x])
        break
    
    for nx in (x - 1, x + 1, 2 * x):
        if 0 <= nx <= MAX and not visited[nx]:
            queue.append(nx)
            visited[nx] = visited[x] + 1
