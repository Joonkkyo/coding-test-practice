from collections import deque
import sys

def bfs(start, graph):
    dist = [-1] * (N + 1)
    dist[start] = 0
    queue.append(start)
    
    while queue:
        node = queue.popleft()
        for i in graph[node]:
            if dist[i] == -1:
                dist[i] = dist[node] + 1
                queue.append(i)
    
    kb_val = 0
    for i in range(N + 1):
        if dist[i] != -1:
            kb_val += dist[i]
    
    return kb_val 
        
        
N, M = map(int, sys.stdin.readline().split())
graph = [[] for _ in range(N + 1)]
queue = deque()
kb_list = []

for _ in range(M):
    A, B = map(int, sys.stdin.readline().split())
    graph[A].append(B)
    graph[B].append(A)

for i in range(1, N + 1):
    kb_list.append(bfs(i, graph))
    
print(kb_list.index(min(kb_list)) + 1)
