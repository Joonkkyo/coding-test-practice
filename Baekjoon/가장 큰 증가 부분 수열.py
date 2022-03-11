N = int(input())
num_list = list(map(int, input().split()))
dp = num_list[:]

for i in range(N):
    for j in range(i):
        if num_list[j] < num_list[i]:
            dp[i] = max(dp[i], dp[j] + num_list[i])
            
print(max(dp))
