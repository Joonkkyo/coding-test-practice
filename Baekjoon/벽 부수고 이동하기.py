from collections import deque


def bfs():
    queue = deque()
    queue.append((0, 0, 0))
    dist[0][0][0] = 1
    while queue:
        y, x, crashed = queue.popleft()
        if y == N - 1 and x == M - 1:
            return dist[y][x][crashed]

        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]
            if 0 <= ny < N and 0 <= nx < M:
                if board[ny][nx] == 0 and dist[ny][nx][crashed] == 0:
                    queue.append((ny, nx, crashed))
                    dist[ny][nx][crashed] = dist[y][x][crashed] + 1

                if board[ny][nx] == 1 and crashed == 0:
                    queue.append((ny, nx, crashed + 1))
                    dist[ny][nx][crashed + 1] = dist[y][x][crashed] + 1

    return -1


N, M = map(int, input().split())
board = [list(map(int, input())) for _ in range(N)]
dist = [[[0] * 2 for i in range(M)] for _ in range(N)]
dy = [0, 0, 1, -1]
dx = [1, -1, 0, 0]
print(bfs())
