from collections import deque


def dfs(x, cnt):
    queue = deque()
    queue.append((x, cnt))
    visited[x] = True
    while queue:
        x, cnt = queue.popleft()
        if x == G:
            return cnt

        for nx in (x + U, x - D):
            if 0 < nx <= F and not visited[nx]:
                visited[nx] = True
                queue.append((nx, cnt + 1))

    return "use the stairs"


F, S, G, U, D = map(int, input().split())
visited = [False] * 1000001
print(dfs(S, 0))
