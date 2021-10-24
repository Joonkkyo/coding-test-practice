import heapq

def solution(scoville, K):
    answer = 0
    heapq.heapify(scoville)
    
    while scoville[0] < K:
        min_val = heapq.heappop(scoville)
        new_val = min_val + heapq.heappop(scoville) * 2
        heapq.heappush(scoville, new_val)
        
        if len(scoville) == 1 and scoville[0] < K:
            return -1
        answer += 1
        
    return answer
