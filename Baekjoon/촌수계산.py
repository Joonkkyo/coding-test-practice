from collections import deque
import sys

def bfs(n):
    queue = deque()
    queue.append(n)
    
    while queue:
        node = queue.popleft()
        
        for i in graph[node]:
            if not visited[i]:
                visited[i] = True
                dist[i] = dist[node] + 1
                queue.append(i)
        print(dist)         
                
# def dfs(n):
#      visited[n] = True
#      for i in graph[n]:
#          if not visited[i]:
#              dist[i] = dist[n] + 1
#              dfs(i)
             
             
N = int(input())
a, b = map(int, input().split())
M = int(input())
graph = [[] for _ in range(N + 1)]
visited = [False] * (N + 1)
dist = [0] * (N + 1)

for _ in range(M):
    x, y = map(int, sys.stdin.readline().split())
    graph[x].append(y)
    graph[y].append(x)
    
bfs(a)
if dist[b] > 0: print(dist[b])
else: print(-1)
