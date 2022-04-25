from collections import deque, defaultdict

N, K = map(int, input().split())
MAX = int(1e5)
queue = deque()
queue.append((N, 0))
visited = [False] * (MAX + 1)
time_dict = defaultdict(int)

while queue:
    x, count = queue.popleft()
    visited[x] = True
    if x == K:
        time_dict[count] += 1

    for nx in (x - 1, x + 1, 2 * x):
        if 0 <= nx <= MAX and not visited[nx]:
            queue.append((nx, count + 1))
            
for key in time_dict.keys():
    print(key)
    print(time_dict[key])
    break
