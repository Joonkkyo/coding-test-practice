from collections import deque
from operator import is_
import sys

T = int(input())
for _ in range(T):
    p = sys.stdin.readline().rstrip()
    n = int(sys.stdin.readline())
    array = sys.stdin.readline().rstrip()
    queue = deque([])
    temp = ''
    for ch in array:
        if ch == '[':
            continue
        
        elif ch == ']' or ch == ',':
            if temp != '':
                queue.append(int(temp))
            temp = ''
            
        else:
            temp += ch
        
    flag, is_reverse = False, False
    for op in p:
        if op == 'R':
            if is_reverse:
                is_reverse = False
            else:
                is_reverse = True
                
        else:
            if queue:
                if is_reverse:
                    queue.pop()
                else:
                    queue.popleft()
            else:
                flag = True
                break
    
    if flag: print("error")
    else:
        queue = list(map(str, queue))
        if is_reverse: 
            queue = queue[::-1]
            print('[' + ",".join(queue) + ']')
        else:
            print('[' + ",".join(queue) + ']')

            
