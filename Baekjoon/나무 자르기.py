N, M = map(int, input().split())
tree = list(map(int, input().split()))

start, end = 0, max(tree) 
answer = 0

def sumCut(mid):
    total = 0
    for i in tree:
        if i > mid:
            total += i - mid
    return total

while start <= end:
    total = 0
    mid = (start + end) // 2
    total = sumCut(mid)
                  
    if total < M:
        end = mid - 1
    else:
        answer = mid
        start = mid + 1
        
print(answer)
