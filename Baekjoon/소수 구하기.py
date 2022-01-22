import math

M, N = map(int, input().split())


def isPrimeNumber(num):
    count = 0
    sqrt_num = int(math.sqrt(num))
    for i in range(1, sqrt_num + 1):
        if num % i == 0:
            count += 1

        if count > 1:
            return False
    return True


for i in range(M, N + 1):
    if isPrimeNumber(i):
        if i == 1:
            continue
        print(i)
