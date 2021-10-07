N = int(input())
dp = [0 for _ in range(N + 1)]
table = []
answer = 0

for _ in range(N):
    day, pay = map(int, input().split())
    table.append((day, pay))

for i in range(N - 1, -1, -1):
    day, pay = table[i][0], table[i][1]
    if i + day > N:
        dp[i] = answer
        continue
    else:
        answer = max(pay + dp[i + day], answer)
        dp[i] = answer
        
print(answer)
    
