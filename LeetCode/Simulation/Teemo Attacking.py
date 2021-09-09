class Solution:
    def findPoisonedDuration(self, timeSeries: List[int], duration: int) -> int:
        answer = 0
        poisoned_time = 0
        for i in range(len(timeSeries) - 1):
            poisoned_time = timeSeries[i] + duration - 1
            
            if poisoned_time < timeSeries[i + 1]:
                answer += duration
            else:
                answer += timeSeries[i + 1] - timeSeries[i]
                
        answer += duration
        return answer
