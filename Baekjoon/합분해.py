N, K = map(int, input().split())
mod = int(1e9)

if K == 1:
    print(1)
    
elif K == 2:
    print(N + 1)
    
else:
    dp = [[0] * (N + 1) for _ in range(K + 1)]
    for i in range(3, K + 1):
        dp[i][1] = i
        
    for i in range(2, N + 1):
        dp[3][i] = dp[3][i - 1] + i + 1
        
    for i in range(4, K + 1):
        for j in range(2, N + 1):
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
            
    print(dp[K][N] % mod)
