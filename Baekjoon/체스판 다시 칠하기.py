N, M = map(int, input().split())
board = []
answer = 1000000

for i in range(N):
   board.append(list(input()))
   
for i in range(N - 7):
    for j in range(M - 7):
        W_case = 0
        B_case = 0
        
        for m in range(i, i + 8):
            for n in range(j, j + 8):
                if (m + n) % 2 == 0:
                    if board[m][n] != 'W':
                        W_case += 1
                    else:
                        B_case += 1
                else:
                    if board[m][n] != 'B':
                        W_case += 1
                    else:
                        B_case += 1
                        
        answer = min(answer, min(W_case, B_case))
        
print(answer)
