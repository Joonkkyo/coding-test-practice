class Solution:
    def sumOfUnique(self, nums: List[int]) -> int:
        lookup = {}
        answer = 0
        
        for num in nums:
            if num in lookup:
                lookup[num] += 1
            else:
                lookup[num] = 1
        
        for key, value in lookup.items():
            if value == 1:
                answer += key
                
        return answer
