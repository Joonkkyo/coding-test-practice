from collections import deque

def solution(m, n, infests, vaccinateds):
    answer = 0
    queue = deque()
    v_pos = set()
    dy = [-1, 1, 0, 0]
    dx = [0, 0, -1, 1]
    dist = [[-1] * n for _ in range(m)]
    for i_y, i_x in infests:
        queue.append((i_y - 1, i_x - 1))
        dist[i_y - 1][i_x - 1] = 0

    for v_y, v_x in vaccinateds:
        v_pos.add((v_y - 1, v_x - 1))

    while queue:
        y, x = queue.popleft()
        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]
            if 0 <= ny < m and 0 <= nx < n and (ny, nx) not in v_pos and dist[ny][nx] == -1:
                queue.append((ny, nx))
                dist[ny][nx] = dist[y][x] + 1

    flatten = sum(dist, [])
    if flatten.count(-1) > len(v_pos):  ## 백신 접종한 직원의 수보다 도달하지 못한 곳이 많으면 -1 리턴
        return -1

    return max(flatten)
