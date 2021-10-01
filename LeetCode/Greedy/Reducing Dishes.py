class Solution:
    def maxSatisfaction(self, satisfaction: List[int]) -> int:
        satisfaction = sorted(satisfaction)
        coef = [i + 1 for i in range(len(satisfaction))]
        total_len = len(satisfaction)
        start = 0
        
        if total_len == 1:
            if satisfaction[0] >= 0: return satisfaction[0]
            else: return 0
            
        while start < total_len:
            sum_1, sum_2 = 0, 0
            for i in range(start, total_len):
                sum_1 += satisfaction[i] * coef[i - start]
                
            for i in range(start + 1, total_len):
                sum_2 += satisfaction[i] * coef[i - start - 1]
            
            if max(sum_1, sum_2) == sum_1:
                return sum_1
            else: start += 1
            
            if start == total_len and sum_2 <= 0:
                return 0
