import heapq
import sys


def dijkstra(s):
    heap = []
    heapq.heappush(heap, (0, s))
    distance[s] = 0

    while heap:
        dist, now = heapq.heappop(heap)

        if distance[now] < dist:
            continue

        for node in graph[now]:
            cost = dist + node[1]
            if cost < distance[node[0]]:
                distance[node[0]] = cost
                heapq.heappush(heap, (cost, node[0]))


N = int(input())
M = int(input())
graph = [[] for _ in range(N + 1)]
INF = float('inf')
distance = [INF] * (N + 1)
count = 0

for _ in range(M):
    u, v, w = map(int, sys.stdin.readline().split())
    graph[u].append((v, w))

start, end = map(int, input().split())
dijkstra(start)
print(distance[end])
