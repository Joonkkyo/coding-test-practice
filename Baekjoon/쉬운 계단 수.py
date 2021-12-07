N = int(input())
dp = []
for _ in range(N + 1):
    dp.append([0] + [1] * 9)

for i in range(1, N + 1):
    dp[i][0], dp[i][9] = dp[i - 1][1], dp[i - 1][8]
    for j in range(1, 9):
        dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1]
 
print(sum(dp[N - 1]) % 1000000000)
        
