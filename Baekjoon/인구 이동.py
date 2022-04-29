from collections import deque


def bfs(s_y, s_x):
    people = board[s_y][s_x]
    idx_set, queue = set(), deque()
    idx_set.add((s_y, s_x))
    queue.append((s_y, s_x))
    visited[s_y][s_x] = True
    while queue:
        y, x = queue.popleft()
        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]
            if 0 <= ny < N and 0 <= nx < N and not visited[ny][nx]:
                if L <= abs(board[ny][nx] - board[y][x]) <= R:
                    visited[ny][nx] = True
                    queue.append((ny, nx))
                    idx_set.add((ny, nx))
                    people += board[ny][nx]

    target = people // len(idx_set)
    for y, x in idx_set:
        board[y][x] = target

    return len(idx_set)


N, L, R = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(N)]
dy = [1, -1, 0, 0]
dx = [0, 0, -1, 1]
answer = 0
while True:
    visited = [[False] * N for _ in range(N)]
    unified = False
    for i in range(N):
        for j in range(N):
            if not visited[i][j]:
                if bfs(i, j) > 1:
                    unified = True

    if not unified:
        break

    answer += 1
print(answer)

