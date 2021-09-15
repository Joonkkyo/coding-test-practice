class Solution:
    def minPairSum(self, nums: List[int]) -> int:
        sorted_nums = sorted(nums)
        answer, start, end = 0, 0, len(nums) - 1
        
        while start < end:
            answer = max(answer, sorted_nums[start] + sorted_nums[end])
            start, end = start + 1, end - 1
            
        return answer
