import sys

def isValid(prev, cur):
    if visited[cur[0]][cur[1]]:
        return False
    
    for i in range(8):
        ny = dy[i] + prev[0]
        nx = dx[i] + prev[1]
        if (ny, nx) == cur:
            return True
    
    else:
        return False
    
    
visited = [[False] * 6 for _ in range(6)]
dy = [1, -1, 1, -1, -2, -2, 2, 2]
dx = [2, 2, -2, -2, -1, 1, -1, 1]
prev = None
answer = 'Valid'
for _ in range(36):
    row, col = list(sys.stdin.readline().rstrip())
    y = ord(row) - ord('A')
    x = int(col) - 1

    if prev == None:
        visited[y][x] = True
        prev = start = (y, x)
        continue
    
    else:
        cur = (y, x)
        if not isValid(prev, cur):
            answer = 'Invalid'
            
        visited[y][x] = True
        prev = cur
        
if answer == 'Valid':
    for i in range(8):
        ny = dy[i] + start[0]
        nx = dx[i] + start[1]
        if (ny, nx) == prev:
            answer = 'Valid'
            break
    else:
        answer = 'Invalid'

print(answer)
