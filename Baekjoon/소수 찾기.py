def isPrimeNum(num):
    if num == 1:
        return False
    
    count = 0
    for i in range(2, num - 1):
        if num % i == 0:
            count += 1
            
    return False if count > 0 else True

N = int(input())
num_list = list(map(int, input().split()))
answer = 0
for num in num_list:
    if isPrimeNum(num): 
        answer += 1
        
print(answer)
