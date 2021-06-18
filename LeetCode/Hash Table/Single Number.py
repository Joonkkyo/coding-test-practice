class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        numMap = Counter(nums)
        
        for key, value in numMap.items():
            if value == 1:
                return key
