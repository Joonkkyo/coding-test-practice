import sys

N, M = map(int, sys.stdin.readline().split())
board = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]
dy = [0, -1, -1, -1, 0, 1, 1, 1]
dx = [-1, -1, 0, 1, 1, 1, 0, -1]
diag_idx = [1, 3, 5, 7]
cloud = [[N, 1], [N, 2], [N - 1, 1], [N - 1, 2]]
answer = 0
for _ in range(M):
    d, s = map(int, sys.stdin.readline().split())
    check = []
    visited = [[False] * N for _ in range(N)]
    for i in range(len(cloud)):
        cloud[i][0] += dy[d - 1] * s
        cloud[i][1] += dx[d - 1] * s
        if cloud[i][0] > N or cloud[i][0] < 1:
            cloud[i][0] = (cloud[i][0] - 1) % N + 1
        if cloud[i][1] > N or cloud[i][1] < 1:
            cloud[i][1] = (cloud[i][1] - 1) % N + 1

    for i in range(len(cloud)):
        board[cloud[i][0] - 1][cloud[i][1] - 1] += 1
        visited[cloud[i][0] - 1][cloud[i][1] - 1] = True

    for i in range(len(cloud)):
        y = cloud[i][0]
        x = cloud[i][1]
        for d in diag_idx:
            ny = y + dy[d]
            nx = x + dx[d]
            if 1 <= ny <= N and 1 <= nx <= N and board[ny - 1][nx - 1] > 0:
                board[y - 1][x - 1] += 1

    cloud = []
    for i in range(N):
        for j in range(N):
            if board[i][j] >= 2 and not visited[i][j]:
                cloud.append([i + 1, j + 1])
                board[i][j] -= 2

for row in board:
    answer += sum(row)

print(answer)
