import sys

def isPrime(n):
    if n == 1:
        return False
    
    for i in range(2, int(n ** 0.5) + 1):
        if n % i == 0:
            return False
        
    return True


while True:
    num = int(sys.stdin.readline())
    if num == 0:
        break
    
    answer = 0
    for i in range(num + 1, 2 * num + 1):
        if isPrime(i):
            answer += 1
    
    print(answer)
