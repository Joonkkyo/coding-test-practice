import sys

N, K = map(int, input().split())
stuff_list = [[0, 0]]
dp = [[0 for _ in range(K + 1)] for _ in range(N + 1)]

for _ in range(N):
    W, V = map(int, sys.stdin.readline().split())
    stuff_list.append([W, V])
    
for i in range(1, N + 1):
    for j in range(1, K + 1):
        w, v = stuff_list[i][0], stuff_list[i][1]
        
        if j < w:
            dp[i][j] = dp[i - 1][j]
        else:
            dp[i][j] = max(dp[i - 1][j - w] + v, dp[i - 1][j])
            
print(dp[-1][-1])
