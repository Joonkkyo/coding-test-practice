N, M = map(int, input().split())
nums = list(map(int, input().split()))

answer = 0
start, end = 0, 1
while start <= end and end <= N:
    num_list = nums[start:end]
    total = sum(num_list)

    if total == M:
        answer += 1
        start += 1

    elif total < M:
        end += 1

    else:
        start += 1
    
print(answer)
