def isPrime(num):
    if num == 1:
        return False
    
    for i in range(2, int(num ** 0.5) + 1):
        if num % i == 0:
            return False
    
    return True


M = int(input())
N = int(input())

min_val, answer = 10000, 0
for i in range(M, N + 1):
    if isPrime(i):
        answer += i
        min_val = min(min_val, i)
        
if answer == 0:
    print(-1)
else:
    print(answer)
    print(min_val)
