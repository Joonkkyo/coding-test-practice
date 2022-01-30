from collections import deque

N, M = map(int, input().split())
nums = [i for i in range(1, N + 1)]
nums = deque(nums)
targets = list(map(int, input().split()))
answer, idx = 0, 0

while True:
    if idx == M:
        break
    
    if nums[0] == targets[idx]:
        nums.popleft()
        idx += 1
    else:
        if nums.index(targets[idx]) <= (len(nums) - 1) / 2:
            answer += 1
            nums.append(nums.popleft())
        else:
            answer += 1
            nums.appendleft(nums.pop())
            
print(answer)
        
