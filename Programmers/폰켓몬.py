from collections import defaultdict

def solution(nums):
    mon_dict = defaultdict(int)
    for num in nums: 
        mon_dict[num] = 1
        
    return min(len(mon_dict.keys()), len(nums) // 2)
