import heapq
import sys

N = int(input())
heap = []
answer = 0

for i in range(N):
    cards = int(sys.stdin.readline())
    heapq.heappush(heap, cards)

if N == 1:
    print(0)
else:    
    while heap:
        sum = heapq.heappop(heap) + heapq.heappop(heap)
        answer += sum
        
        if not heap:
            print(answer)
            break

        heapq.heappush(heap, sum)
