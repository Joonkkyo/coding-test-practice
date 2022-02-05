from collections import deque
import sys

N = int(input())
graph = [[] for _ in range(N + 1)]
parents = [0 for _ in range(N + 1)]

for _ in range(N - 1):
    y, x = map(int, sys.stdin.readline().split())
    graph[y].append(x)
    graph[x].append(y)
    
queue = deque()
queue.append(1)
while queue:
    node = queue.popleft()
    for i in graph[node]:
        if parents[i] == 0:
            parents[i] = node
            queue.append(i)

for i in range(2, N + 1):
    print(parents[i])
    
