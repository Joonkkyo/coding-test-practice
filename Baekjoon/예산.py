N = int(input())
budgets = list(map(int, input().split()))
M = int(input())

start, end = 0, max(budgets)
while start <= end:
    mid = (start + end) // 2
    total = 0
    
    for budget in budgets:
        if budget > mid:
            total += mid
        else:
            total += budget
            
    if total > M:
        end = mid - 1
    else:
        start = mid + 1
        
print(end)
