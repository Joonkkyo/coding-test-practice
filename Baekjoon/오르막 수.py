N = int(input())
dp = []
for _ in range(N + 1):
    dp.append([1] * 10)

for i in range(2, N + 1):
    for j in range(1, 10):
        dp[i][j] = dp[i][j - 1] + dp[i - 1][j]

print(sum(dp[N]) % 10007)
