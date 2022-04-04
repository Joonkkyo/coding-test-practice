import heapq
import sys

heap = []
N = int(input())
for _ in range(N):
    num_list = list(map(int, sys.stdin.readline().split()))
    for num in num_list:
        if len(heap) < N:
            heapq.heappush(heap, num)
        else:
            if heap[0] < num:
                heapq.heappop(heap)
                heapq.heappush(heap, num)
            
print(heapq.heappop(heap))
