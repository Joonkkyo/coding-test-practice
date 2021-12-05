T = int(input())
dp = [0] * 30
dp[0], dp[1] = 1, 1
for i in range(2, 30):
    dp[i] = dp[i - 1] * i
    
for _ in range(T):
    N, M = map(int, input().split())
    if N > M: print(int(dp[N] / (dp[N - M] * dp[M])))
    else: print(int(dp[M] / (dp[M - N] * dp[N])))
