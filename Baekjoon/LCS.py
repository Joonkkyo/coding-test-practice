str1 = input()
str2 = input()

row, col = len(str1), len(str2)
dp = [[0] * col for _ in range(row)]

flag = False
for i in range(row):
    if flag: 
        dp[i][0] = 1
        continue
    
    if str1[i] == str2[0]:
        dp[i][0] = 1
        flag = True

flag = False
for j in range(col):
    if flag: 
        dp[0][j] = 1
        continue
    
    if str1[0] == str2[j]:
        dp[0][j] = 1
        flag = True
        
for i in range(1, row):
    for j in range(1, col):
        if str1[i] == str2[j]:
            dp[i][j] = dp[i - 1][j - 1] + 1
        else:
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j])

                    
print(dp[row - 1][col - 1])
