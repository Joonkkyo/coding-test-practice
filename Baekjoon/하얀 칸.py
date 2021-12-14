board = []
for _ in range(8):
    board.append(list(input()))

answer = 0
for i in range(8):
    for j in range(8):
        if i % 2 == 0:
            if j % 2 == 0 and board[i][j] == 'F': answer += 1
        else:
            if j % 2 != 0 and board[i][j] == 'F': answer += 1
print(answer)
