class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        heap = []
        for stone in stones:
            heapq.heappush(heap, (-stone, stone))
        
        while len(heap) > 1:
            stone1 = heapq.heappop(heap)[1]
            stone2 = heapq.heappop(heap)[1]
            
            if stone1 != stone2:
                diff = abs(stone1 - stone2)
                heapq.heappush(heap, (-diff, diff))
                
        if heap: return heap[0][1]
        else: return 0
