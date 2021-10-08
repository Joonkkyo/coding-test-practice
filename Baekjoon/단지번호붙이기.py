import heapq

N = int(input())
board, heap = [], []
visited = [[False] * N for _ in range(N)]
for _ in range(N):
    board.append(list(map(int, input())))

dx = [-1, 1, 0, 0]
dy = [0, 0, 1, -1]
total = 0

def dfs(y, x):
    global total
    if not (0 <= y < N and 0 <= x < N) or visited[y][x] or board[y][x] == 0:
        return
    
    total += 1
    visited[y][x] = True
    
    for i in range(4):
        dfs(y + dy[i], x + dx[i])
        
for i in range(N):
    for j in range(N):
        if not visited[i][j] and board[i][j] == 1:
            dfs(i, j)
            heapq.heappush(heap, total)
            total = 0
            
print(len(heap))
while heap:
    print(heapq.heappop(heap))


    
