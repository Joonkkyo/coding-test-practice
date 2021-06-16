class Solution:
    def repeatedNTimes(self, nums: List[int]) -> int:
        lookup = {}
        
        for num in nums:
            if num in lookup:
                return num
            lookup[num] = 1

