class Solution:
    def minOperations(self, nums: List[int]) -> int:
        answer = 0
        
        for i in range(len(nums) - 1):
            if nums[i] < nums[i + 1]:
                continue
            else:
                answer += nums[i] - nums[i + 1] + 1
                nums[i + 1] += nums[i] - nums[i + 1] + 1
                
        return answer
