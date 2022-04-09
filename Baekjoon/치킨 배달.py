from itertools import combinations
import copy
import sys

def cal_dist(h_y, h_x, c_y, c_x):
    return abs(h_y - c_y) + abs(h_x - c_x)


N, M = map(int, sys.stdin.readline().split())
board = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]
chicken_list = []    
answer = 1e5
for i in range(N):
    for j in range(N):
        if board[i][j] == 2:
            chicken_list.append((i, j))

for comb in combinations(chicken_list, M):
    city = copy.deepcopy(board)
    dist_list = []
    for i in range(N):
        for j in range(N):
           if (i, j) not in comb and city[i][j] == 2:
               city[i][j] = 0
    
    sum_dist, min_dist = 0, 1e5
    for i in range(N):
        for j in range(N):
            if city[i][j] == 1:
                min_dist = 1e5
                for idx in comb:
                    min_dist = min(min_dist, cal_dist(i, j, idx[0], idx[1]))
                sum_dist += min_dist
                
    answer = min(answer, sum_dist)  
print(answer)  
