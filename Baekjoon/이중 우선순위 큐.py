import heapq
import sys

T = int(input())
for _ in range(T):
    N = int(sys.stdin.readline())
    min_heap, max_heap = [], []
    min_ans, max_ans = 0, 0
    num_dict = {}
    for _ in range(N):
        op, num = sys.stdin.readline().split()
        num = int(num)
        if op == "I":
            heapq.heappush(min_heap, num)
            heapq.heappush(max_heap, (-num, num))
            if num not in num_dict.keys():
                num_dict[num] = 1
            else:
                num_dict[num] += 1
        else:
            if num == -1:
                while min_heap:
                    min_num = heapq.heappop(min_heap)
                    if num_dict[min_num] > 0:
                        num_dict[min_num] -= 1 
                        break    
            else:
                while max_heap:
                    max_num = heapq.heappop(max_heap)[1]                
                    if num_dict[max_num] > 0:
                        num_dict[max_num] -= 1       
                        break
                    
    while max_heap:
        if num_dict[max_heap[0][1]] == 0:
            heapq.heappop(max_heap)
        else:
            break
            
    while min_heap:
        if num_dict[min_heap[0]] == 0:
            heapq.heappop(min_heap)
        else:
            break

    if not max_heap or not min_heap:
        print("EMPTY")
    else:
        print(max_heap[0][1], min_heap[0])
