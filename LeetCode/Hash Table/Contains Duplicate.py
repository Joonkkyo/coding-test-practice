class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        lookup = {}
        
        for i in nums:
            if i not in lookup:
                lookup[i] = 1
            else:
                return True
        
        return False
