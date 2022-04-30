import copy
from collections import deque


def spread(y, x, d):
    visited = [[False] * C for _ in range(R)]
    tmp = 5
    s_y, s_x = y + dy[d - 1], x + dx[d - 1]
    total_board[s_y][s_x] += tmp
    queue = deque()
    queue.append((s_y, s_x, tmp))
    visited[s_y][s_x] = True
    dt = [-1, 0, 1]
    while queue:
        y, x, tmp = queue.popleft()
        if tmp == 0:
            break

        if d == 1:
            for t in dt:
                ny = y + t
                nx = x + dx[d - 1]
                if 0 <= ny < R and 0 <= nx < C and not visited[ny][nx]:
                    if t == -1:
                        if (y, x, 0) in wall_info or (y - 1, x, 1) in wall_info:
                            continue
                    elif t == 0:
                        if (y, x, 1) in wall_info:
                            continue

                    else:
                        if (y + 1, x, 0) in wall_info or (y + 1, x, 1) in wall_info:
                            continue

                    queue.append((ny, nx, tmp - 1))
                    visited[ny][nx] = True
                    total_board[ny][nx] += tmp - 1

        elif d == 2:
            for t in dt:
                ny = y + t
                nx = x + dx[d - 1]
                if 0 <= ny < R and 0 <= nx < C and not visited[ny][nx]:
                    if t == -1:
                        if (y, x, 0) in wall_info or (ny, nx, 1) in wall_info:
                            continue
                    elif t == 0:
                        if (ny, nx, 1) in wall_info:
                            continue

                    else:
                        if (y + 1, x, 0) in wall_info or (ny, nx, 1) in wall_info:
                            continue

                    queue.append((ny, nx, tmp - 1))
                    visited[ny][nx] = True
                    total_board[ny][nx] += tmp - 1

        elif d == 3:
            for t in dt:
                ny = y + dy[d - 1]
                nx = x + t
                if 0 <= ny < R and 0 <= nx < C and not visited[ny][nx]:
                    if t == -1:
                        if (y, x - 1, 0) in wall_info or (y, x - 1, 1) in wall_info:
                            continue
                    elif t == 0:
                        if (y, x, 0) in wall_info:
                            continue
                    else:
                        if (y, x, 1) in wall_info or (y, x + 1, 0) in wall_info:
                            continue

                    queue.append((ny, nx, tmp - 1))
                    visited[ny][nx] = True
                    total_board[ny][nx] += tmp - 1

        else:
            for t in dt:
                ny = y + dy[d - 1]
                nx = x + t
                if 0 <= ny < R and 0 <= nx < C and not visited[ny][nx]:
                    if t == -1:
                        if (y, x - 1, 1) in wall_info or (ny, nx, 0) in wall_info:
                            continue
                    elif t == 0:
                        if (ny, nx, 0) in wall_info:
                            continue
                    else:
                        if (y, x, 1) in wall_info or (ny, nx, 0) in wall_info:
                            continue

                    queue.append((ny, nx, tmp - 1))
                    visited[ny][nx] = True
                    total_board[ny][nx] += tmp - 1


def adjust_temp():
    check = [[False] * C for _ in range(R)]
    new_board = copy.deepcopy(total_board)
    for i in range(R):
        for j in range(C):
            if not check[i][j]:
                y, x = i, j
                check[i][j] = True
                for d in range(4):
                    ny = y + dy[d]
                    nx = x + dx[d]
                    if 0 <= ny < R and 0 <= nx < C and not check[ny][nx]:
                        if (d == 0 and (y, x, 1) in wall_info) or (d == 1 and (ny, nx, 1) in wall_info) \
                                or (d == 2 and (y, x, 0) in wall_info) or (d == 3 and (ny, nx, 0) in wall_info):
                            continue

                        diff = abs(total_board[ny][nx] - total_board[y][x])
                        if total_board[ny][nx] > total_board[y][x]:
                            new_board[ny][nx] -= diff // 4
                            new_board[y][x] += diff // 4
                        else:
                            new_board[ny][nx] += diff // 4
                            new_board[y][x] -= diff // 4
            check[i][j] = True

    for i in range(R):
        for j in range(C):
            total_board[i][j] = new_board[i][j]


def side_temp_down():
    for i in range(C):
        if total_board[0][i] > 0:
            total_board[0][i] -= 1

        if total_board[R - 1][i] > 0:
            total_board[R - 1][i] -= 1

    for i in range(1, R - 1):
        if total_board[i][0] > 0:
            total_board[i][0] -= 1

        if total_board[i][C - 1] > 0:
            total_board[i][C - 1] -= 1


R, C, K = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(R)]
W = int(input())
wall_info = set()
for _ in range(W):
    y, x, t = map(int, input().split())
    wall_info.add((y - 1, x - 1, t))
dy = [0, 0, -1, 1]
dx = [1, -1, 0, 0]


answer = 0
targets, devices = [], []
for i in range(R):
    for j in range(C):
        if board[i][j] == 5:
            targets.append((i, j))

        if 1 <= board[i][j] <= 4:
            devices.append((i, j, board[i][j]))

total_board = [[0] * C for _ in range(R)]
while True:
    is_over = True
    for device in devices:
        spread(device[0], device[1], device[2])

    adjust_temp()
    side_temp_down()
    answer += 1
    if answer >= 101:
        break

    for (y, x) in targets:
        if total_board[y][x] < K:
            is_over = False
            break

    if is_over:
        break

print(answer)
