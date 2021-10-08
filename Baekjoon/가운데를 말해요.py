import heapq
import sys

N = int(input())
min_heap, max_heap = [], []

for _ in range(N):
    num = int(sys.stdin.readline())
    
    if len(min_heap) == len(max_heap):
        heapq.heappush(max_heap, -num)
    else:
        heapq.heappush(min_heap, num)
        
    if min_heap and max_heap:
        if max_heap[0] * -1 > min_heap[0]:
            min_val = heapq.heappop(min_heap)
            max_val = heapq.heappop(max_heap) * -1
            
            heapq.heappush(max_heap, min_val * -1)
            heapq.heappush(min_heap, max_val)
            
    print(max_heap[0] * -1)
