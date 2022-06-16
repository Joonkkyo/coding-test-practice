import heapq
import sys


def dijkstra(s, distance):
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


def cal_dist(a, b):
    distance = [INF] * (N + 1)
    dijkstra(a, distance)
    return distance[b]


N, E = map(int, input().split())
graph = [[] for _ in range(N + 1)]
INF = float('inf')
answer = 0

for _ in range(E):
    u, v, w = map(int, sys.stdin.readline().split())
    graph[u].append((v, w))
    graph[v].append((u, w))

v1, v2 = map(int, input().split())

if (cal_dist(1, v1) == INF or cal_dist(v1, v2) == INF or cal_dist(v2, N) == INF) \
        or (cal_dist(1, v2) == INF or cal_dist(v2, v1) == INF or cal_dist(v1, N) == INF):
    print(-1)
else:
    answer = min(cal_dist(1, v2) + cal_dist(v2, v1) + cal_dist(v1, N), cal_dist(1, v1) + cal_dist(v1, v2) + cal_dist(v2, N))
    print(answer)
