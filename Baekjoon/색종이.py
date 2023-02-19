import sys

board = [[0] * 100 for _ in range(100)]
answer = 0

N = int(input())
for i in range(N):
    y, x = map(int, sys.stdin.readline().split())

    for i in range(y, y + 10):
        for j in range(x, x + 10):
            if board[i][j] == 0:
                board[i][j] = 1
                answer += 1

print(answer)
