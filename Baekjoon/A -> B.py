from collections import deque

A, B = map(int, input().split())
queue = deque()
queue.append((A, 1))
possible = False

while queue:
    num, count = queue.popleft()
    if num > B:
        continue
    if num == B: 
        print(count)
        possible = True
        break
    queue.append((int(str(num) + "1"), count + 1))
    queue.append((num * 2, count + 1))

if not possible: print(-1)
