import copy
    
def add_fish():
    min_val = min(board[0])
    for i in range(len(fishes)):
        if board[0][i] == min_val:
            board[0][i] += 1


def fish_move_1():
    f_y, f_x = 1, 1
    s_x = 0
    while s_x + f_y + f_x <= N:
        for y in range(f_y):
            for x in range(f_x):
                board[f_x - x][s_x + f_x + y] = board[y][x + s_x]
                board[y][x + s_x] = -1
            
        s_x += f_x
        if f_y == f_x: 
            f_y += 1
        else:
            f_x += 1


def adjust_fish():
    new_board = copy.deepcopy(board)
    visited = [[False] * N for _ in range(N)]
    dy = [0, 0, 1, -1]
    dx = [1, -1, 0, 0]
    for i in range(N):
        for j in range(N):
            if board[i][j] != -1:
                visited[i][j] = True
                y, x = i, j
                for k in range(4):
                    ny = y + dy[k]
                    nx = x + dx[k]
                    if 0 <= ny < N and 0 <= nx < N and board[ny][nx] != -1 and not visited[ny][nx]:
                        d = abs(board[y][x] - board[ny][nx]) // 5
                        if d > 0:
                            if board[y][x] > board[ny][nx]:
                                new_board[y][x] -= d
                                new_board[ny][nx] += d
                            else:
                                new_board[y][x] += d
                                new_board[ny][nx] -= d    
                                
    for i in range(N):
        for j in range(N):
            board[i][j] = new_board[i][j]


def make_1D():
    idx_arr = []
    pivot = 0
    for i in range(N):
        if board[0][i] != -1 and board[1][i] != -1:
            idx_arr.append(i)
        
    for idx in idx_arr:
        for i in range(N):
            if board[i][idx] != -1:
                board[0][pivot] = board[i][idx]
                board[i][idx] = -1
                pivot += 1
                
            
def fish_move_2():
    temp = board[0][:N // 2]
    for i in range(len(temp)):
        board[1][N - i - 1] = temp[i]
        board[0][i] = -1
    
    matrix = []
    s_x = N // 2 + N // 4
    matrix.append(board[0][N // 2 : s_x])
    matrix.append(board[1][N // 2 : s_x])
    for i in range(2):
        for j in range(N // 2, s_x):
            board[i][j] = -1
            
    row, col = 2, s_x - N // 2
    rotated_matrix = [[0] * col for _ in range(row)]
    for i in range(row):
        for j in range(col):
            rotated_matrix[row - i - 1][col - j - 1] = matrix[i][j]

    for i in range(row):
        for j in range(col):
            board[i + 2][s_x + j] = rotated_matrix[i][j]
    
    
N, K = map(int, input().split())
fishes = list(map(int, input().split()))
board = [[-1] * N for _ in range(N)]
for i in range(N):
    board[0][i] = fishes[i]
    
answer = 0
while max(board[0]) - min(board[0]) > K:
    add_fish()
    fish_move_1()
    adjust_fish()
    make_1D()
    fish_move_2()
    adjust_fish()
    make_1D()
    answer += 1
    
print(answer)
