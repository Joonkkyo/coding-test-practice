import heapq

def solution(n, works):
    answer = 0
    heap = []
    for work in works:
        heapq.heappush(heap, (work * -1, work))

    while heap and n > 0:
        work = heapq.heappop(heap)[1]
        if work > 0: 
            work -= 1
            n -= 1
            heapq.heappush(heap, (work * -1, work))
    
    for i in range(len(heap)):
        answer += heap[i][1] ** 2     
        
    return answer
