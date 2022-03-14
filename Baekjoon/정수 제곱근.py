n = int(input())
start, end = 0, 1e10
answer = 1e10

while start <= end:
    mid = (start + end) // 2
    if mid ** 2 < n:
        start = mid + 1
    
    else:
        answer = min(answer, mid)
        end = mid - 1
   
print(int(answer))
