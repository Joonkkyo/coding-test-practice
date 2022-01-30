def isPrime(num):
    count = 0
    if num == 1:
        return True
    
    for i in range(2, num + 1):
        if num % i == 0:
            count += 1
        if count > 1:
            return False
    return True

def isPalin(num):
    num = str(num)
    for i in range(len(num) // 2):
        if num[i] == num[len(num) - 1 - i]:
            continue
        else:
            return False
        
    return True


N = int(input())
while True:
    if isPalin(N) and isPrime(N):
        break
    else: N += 1
    
print(N)
    
        
