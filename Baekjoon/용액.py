N = int(input())
liquid = list(map(int, input().split()))

start, end = 0, N - 1
min_val = int(1e11)

while start < end:
    mid = (start + end) // 2
    result = liquid[start] + liquid[end]
    
    if abs(result) <= min_val:
        answer = [liquid[start], liquid[end]]
        min_val = abs(result)
    
    if result > 0:
        end -= 1
    else:
        start += 1
        
print(answer[0], answer[1])
