import heapq
import sys

n = int(input())
heap = []
for _ in range(n):
    nums = list(map(int, sys.stdin.readline().split()))

    if nums[0] == 0:
        if heap: print(heapq.heappop(heap) * -1)
        else: print(-1)
    
    else:
        for i in range(1, nums[0] + 1):
            heapq.heappush(heap, -1 * nums[i])
