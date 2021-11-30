K, N = map(int, input().split())
lan = []
for _ in range(K):
   num = int(input())
   lan.append(num)

answer = 0
start, end = 0, max(lan)
while start <= end:
    total = 0
    mid = (start + end) // 2
    if mid == 0:
        mid = 1
        
    for i in lan:
        total += i // mid

    if total < N:
        end = mid - 1
    else:
        answer = mid
        start = mid + 1
        
print(answer)
        
        
