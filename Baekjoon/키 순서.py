import sys

N, M = map(int, input().split())
INF = float('inf')
graph = [[INF] * (N + 1) for _ in range(N + 1)]
answer = 0

for _ in range(M):
    u, v = map(int, sys.stdin.readline().split())
    graph[u][v] = 1

for i in range(1, N + 1):
    for j in range(1, N + 1):
        if i == j:
            graph[i][j] = 0

for k in range(1, N + 1):
    for i in range(1, N + 1):
        for j in range(1, N + 1):
            graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j])

for i in range(1, N + 1):
    idx_list = []
    for j in range(1, N + 1):
        if graph[j][i] != INF and graph[j][i] != 0:
            idx_list.append(j)

    for j in range(1, N + 1):
        if graph[i][j] != INF and graph[i][j] != 0:
            idx_list.append(j)

    if len(idx_list) == N - 1:
        answer += 1

print(answer)
