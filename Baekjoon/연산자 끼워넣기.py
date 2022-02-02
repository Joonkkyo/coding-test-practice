from itertools import permutations

N = int(input())
init_nums = list(map(int, input().split()))
op_list = list(map(int, input().split()))
perm_list = []

for i in range(len(op_list)):
    if op_list[i] != 0:
        for j in range(op_list[i]):
            perm_list.append(i)
        
min_ans = 999999999
max_ans = -999999999

for perm in permutations(perm_list):
    nums = init_nums[:]
    for i in range(len(perm)):
        if perm[i] == 0:
            result = nums[i] + nums[i + 1]
        elif perm[i] == 1:
            result = nums[i] - nums[i + 1]
        elif perm[i] == 2:
            result = nums[i] * nums[i + 1]
        else:
            result = abs(nums[i]) // nums[i + 1]
            if nums[i] < 0:
                result *= -1
        
        nums[i + 1] = result
        
    min_ans = min(min_ans, nums[len(nums) - 1])
    max_ans = max(max_ans, nums[len(nums) - 1])
    
print(max_ans)
print(min_ans)
