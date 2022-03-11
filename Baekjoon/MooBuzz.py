N = int(input())

start, end = 0, int(1e10)
while start <= end:
    mid = (start + end) // 2

    if mid - (mid // 3) - (mid // 5) + (mid // 15) < N:
        start = mid + 1
    
    elif mid - (mid // 3) - (mid // 5) + (mid // 15) == N:
        answer = mid
        break
    
    else:
        end = mid - 1
    
while answer % 3 == 0 or answer % 5 == 0:
    answer -= 1
    
print(answer)
