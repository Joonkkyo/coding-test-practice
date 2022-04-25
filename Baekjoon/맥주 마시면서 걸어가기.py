from collections import deque
import sys

def dfs():
    queue = deque()
    queue.append((start_x, start_y))
    while queue:
        x, y = queue.popleft()
        if abs(x - target_x) + abs(y - target_y) <= 1000:
            print("happy")
            return
        
        for i in range(store_cnt):
            if not visited[i]:
                nx, ny = store_list[i]
                if abs(x - nx) + abs(y - ny) <= 1000:
                    queue.append((nx, ny))
                    visited[i] = True
    else:
        print("sad")
        return

T = int(input())
for _ in range(T):
    store_list = []
    store_cnt = int(sys.stdin.readline())
    start_x, start_y = map(int, sys.stdin.readline().split())
    
    for _ in range(store_cnt):
        store_x, store_y = map(int, sys.stdin.readline().split())
        store_list.append((store_x, store_y))
        
    visited = [False] * store_cnt
    target_x, target_y = map(int, sys.stdin.readline().split())
    dfs()
