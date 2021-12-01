from collections import deque
import sys

dq = deque([])
N = int(input())
for _ in range(N):
    op = sys.stdin.readline().split()
    if op[0] == "push_front":
        dq.appendleft(int(op[1]))
        
    elif op[0] == "push_back":
        dq.append(int(op[1]))
        
    elif op[0] == "pop_front":
        if dq: print(dq.popleft())
        else: print(-1)
        
    elif op[0] == "pop_back":
        if dq: print(dq.pop())
        else: print(-1)
        
    elif op[0] == "size":
        print(len(dq))
        
    elif op[0] == "empty":
        if dq: print(0)
        else: print(1)
        
    elif op[0] == "front":
        if dq: print(dq[0])
        else: print(-1)
        
    else:
        if dq: print(dq[-1])
        else: print(-1)
