N = int(input())
M = int(input())
S = input()

pattern = "IOI" + "OI" * (N - 1)
limit = N * 2
flag = False
count, answer = 0, 0
for i in range(len(S) - 1):

    if S[i] == 'I':
        flag = True
    
    if flag and S[i] != S[i + 1]:
        count += 1

    if S[i] == S[i + 1] or i == len(S) - 2:
        if count >= limit:
            answer += 1 + (count - limit) // 2

        flag = False
        count = 0

print(answer)
