class Solution:
    def getMaximumGenerated(self, n: int) -> int:
        nums = [0 for _ in range(n + 1)]
        answer = 0
        
        if n == 0:
            return 0
        elif n == 1:
            return 1
        
        nums[0], nums[1] = 0, 1
        
        for i in range(2, n + 1):
            if i % 2 == 0:
                nums[i] = nums[i // 2]
            else:
                nums[i] = nums[i // 2] + nums[i // 2 + 1]
                
            answer = max(answer, nums[i])
            
        return answer
