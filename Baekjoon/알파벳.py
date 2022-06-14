import sys


def dfs(y, x, dist):
    global answer
    answer = max(answer, dist)

    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
        if 0 <= ny < R and 0 <= nx < C and board[ny][nx] not in alpha:
            alpha.add(board[ny][nx])
            dfs(ny, nx, dist + 1)
            alpha.remove(board[ny][nx])


# sys.setrecursionlimit(10**9)
R, C = map(int, input().split())
board = [list(sys.stdin.readline().rstrip()) for _ in range(R)]
dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]
alpha = set(board[0][0])
answer = 0

dfs(0, 0, 1)
print(answer)
