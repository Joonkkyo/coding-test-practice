class Solution:
    def arrayPairSum(self, nums: List[int]) -> int:
        nums = sorted(nums)
        answer = 0 
        for i in range(len(nums) // 2):
            answer += min(nums[i * 2], nums[i * 2 + 1])
            
        return answer
