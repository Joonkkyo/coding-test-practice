def solution(price, money, count):
    answer = -1
    sum = 0
    for i in range(count):
        sum += (i + 1) * price
    answer = sum - money
    
    if money - sum >= 0:
        answer = 0
        
    return answer
