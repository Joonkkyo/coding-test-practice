N, K = map(int, input().split())
num, deno = N, K
for i in range(1, K):
    num *= N - i
for i in range(1, K):
    deno *= i

if deno == 0: answer = 1
else: answer = int(num / deno)
print(answer)
    
