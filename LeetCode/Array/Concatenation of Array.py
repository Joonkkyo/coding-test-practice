class Solution:
    def getConcatenation(self, nums: List[int]) -> List[int]:
        nums_copy = nums
        
        for i in range(len(nums)):
            nums.append(nums_copy[i])
            
        return nums
