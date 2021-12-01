nums = list(map(int, input().split()))
total = 0 
for num in nums:
    total += num * num
    
answer = total % 10
print(answer)
