import sys

T = int(input())
div = 1000000009
dp = [0] * 1000001

dp[1], dp[2], dp[3] = 1, 2, 4
for i in range(4, 1000001):
    dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % div
    
for _ in range(T):
    target = int(sys.stdin.readline())
    print(dp[target])
