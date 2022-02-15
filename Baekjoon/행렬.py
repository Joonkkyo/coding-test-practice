import sys

def reverseArr(arr, x, y):
    for i in range(x, x + 3):
        for j in range(y, y + 3):
            arr[i][j] ^= 1
            
            
N, M = map(int, input().split())
board, target = [], []
answer = 0

for _ in range(N):
    board.append(list(map(int, sys.stdin.readline().rstrip())))

for _ in range(N):
    target.append(list(map(int, sys.stdin.readline().rstrip())))
             

for i in range(N - 2):
    for j in range(M - 2):
        if board[i][j] != target[i][j]:
            reverseArr(board, i, j)
            answer += 1
      
flag = True   
for i in range(N):
    for j in range(M):
        if board[i][j] != target[i][j]:
            flag = False
            break

if flag: print(answer)
else: print(-1)
