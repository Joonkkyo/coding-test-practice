import sys

def get_pos(y, x, s):
    global max_empty, max_friend
    global cur_y, cur_x
    empty_cnt, friend_cnt = 0, 0
    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
        if not (0 <= ny < N and 0 <= nx < N):
            continue
        
        if board[ny][nx] == 0:
            empty_cnt += 1
            
        if board[ny][nx] in like_dict[s]:
            friend_cnt += 1
                
    if max_friend < friend_cnt or (max_friend == friend_cnt and max_empty < empty_cnt):
        cur_y, cur_x = y, x
        max_friend, max_empty = friend_cnt, empty_cnt

    return cur_y, cur_x


def cal_score(y, x, s):
    score, friend = 0, 0
    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
        if not (0 <= ny < N and 0 <= nx < N):
            continue
        if board[ny][nx] in like_dict[s]:
            friend += 1
            
    if friend == 0: score = 0
    else: score = 10 ** (friend - 1)
    
    return score


N = int(input())
like_dict = {}
student_list = []
board = [[0] * N for _ in range(N)] 
dy = [-1, 1, 0, 0]
dx = [0, 0, 1, -1]
answer = 0 

for _ in range(N ** 2):
    student_info = list(map(int, sys.stdin.readline().split()))
    key, val = student_info[0], set(student_info[1:])
    like_dict[key] = val
    student_list.append(key)

for student in student_list:
    max_empty, max_friend = -1, -1
    cur_y, cur_x = 0, 0
    for i in range(N):
        for j in range(N):
            if board[i][j] == 0:
                y, x = get_pos(i, j, student)
    board[y][x] = student

for i in range(N):
    for j in range(N):
        answer += cal_score(i, j, board[i][j])

print(answer)
