import sys


def find(x):
    if parent[x] != x:
        parent[x] = find(parent[x])
    return parent[x]


def union(x, y):
    x = find(x)
    y = find(y)

    if x < y:
        parent[y] = x
    else:
        parent[x] = y


V, E = map(int, input().split())
parent = [0] * (V + 1)
edges = []
answer = 0

for i in range(1, V + 1):
    parent[i] = i

for _ in range(E):
    a, b, cost = map(int, sys.stdin.readline().split())
    edges.append((cost, a, b))

edges.sort()

for i in range(E):
    cost, a, b = edges[i]
    print(parent)
    if find(a) != find(b):
        union(a, b)
        answer += cost

print(answer)

