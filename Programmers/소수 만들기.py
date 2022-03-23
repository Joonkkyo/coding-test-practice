from itertools import combinations

def isPrime(num):
    count = 0
    if num == 1:
        return False
    else:
        for i in range(2, int(num ** 0.5) + 1):
            if num % i == 0:
                return False
            else:
                continue
                
    return True
            
def solution(nums):
    answer = 0
    for num in combinations(nums, 3):
        if isPrime(sum(list(num))):
            answer += 1
    
    return answer
