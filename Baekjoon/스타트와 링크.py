from itertools import combinations
import sys

N = int(input())
board = []
for i in range(N):
    board.append(list(map(int, sys.stdin.readline().split())))
    
answer = 1e6
arr = [i for i in range(N)]

for comb in combinations(arr, N // 2):
    start, link = 0, 0
    temp1 = list(comb)
    temp2 = list(set(arr) - set(temp1))

    for idx in combinations(temp1, 2):
        start += board[idx[0] - 1][idx[1] - 1] + board[idx[1] - 1][idx[0] - 1] 
        
    for idx in combinations(temp2, 2):
        link += board[idx[0] - 1][idx[1] - 1] + board[idx[1] - 1][idx[0] - 1] 
        
    answer = min(answer, abs(start - link))
    
print(answer)
