import sys

king, stone, N = input().split()
board = [[0] * 8 for _ in range(8)]
k_x, k_y = ord(king[0]) - ord('A'), int(king[1]) - 1
s_x, s_y = ord(stone[0]) - ord('A'), int(stone[1]) - 1

def isValidMove(y, x):
    if 0 <= y < 8 and 0 <= x < 8:
        return True
    return False

y, x = k_y, k_x

for _ in range(int(N)):
    command = sys.stdin.readline().strip()
    if command == 'R':
        ny, nx = y, x + 1
        if ny == s_y and nx == s_x:
            s_ny, s_nx = s_y, s_x + 1
            if isValidMove(s_ny, s_nx): s_y, s_x = s_ny, s_nx
            else: continue
            
        if isValidMove(ny, nx): y, x = ny, nx
        else: continue
    
    elif command == 'L':
        ny, nx = y, x - 1
        if ny == s_y and nx == s_x:
            s_ny, s_nx = s_y, s_x - 1
            if isValidMove(s_ny, s_nx): s_y, s_x = s_ny, s_nx
            else: continue
            
        if isValidMove(ny, nx): y, x = ny, nx
        else: continue   
               
    elif command == 'B':
        ny, nx = y - 1, x
        if ny == s_y and nx == s_x:
            s_ny, s_nx = s_y - 1, s_x
            if isValidMove(s_ny, s_nx): s_y, s_x = s_ny, s_nx
            else: continue
            
        if isValidMove(ny, nx): y, x = ny, nx
        else: continue           
         
    elif command == 'T':
        ny, nx = y + 1, x
        if ny == s_y and nx == s_x:
            s_ny, s_nx = s_y + 1, s_x
            if isValidMove(s_ny, s_nx): s_y, s_x = s_ny, s_nx
            else: continue
            
        if isValidMove(ny, nx): y, x = ny, nx
        else: continue  
        
    elif command == 'RT':
        ny, nx = y + 1, x + 1
        if ny == s_y and nx == s_x:
            s_ny, s_nx = s_y + 1, s_x + 1
            if isValidMove(s_ny, s_nx): s_y, s_x = s_ny, s_nx
            else: continue
            
        if isValidMove(ny, nx): y, x = ny, nx
        else: continue  
        
    elif command == 'LT':
        ny, nx = y + 1, x - 1
        if ny == s_y and nx == s_x:
            s_ny, s_nx = s_y + 1, s_x - 1
            if isValidMove(s_ny, s_nx): s_y, s_x = s_ny, s_nx
            else: continue
            
        if isValidMove(ny, nx): y, x = ny, nx
        else: continue  
        
    elif command == 'RB':
        ny, nx = y - 1, x + 1
        if ny == s_y and nx == s_x:
            s_ny, s_nx = s_y - 1, s_x + 1
            if isValidMove(s_ny, s_nx): s_y, s_x = s_ny, s_nx
            else: continue
            
        if isValidMove(ny, nx): y, x = ny, nx
        else: continue  
        
    elif command == 'LB':
        ny, nx = y - 1, x - 1
        if ny == s_y and nx == s_x:
            s_ny, s_nx = s_y - 1, s_x - 1
            if isValidMove(s_ny, s_nx): s_y, s_x = s_ny, s_nx
            else: continue
            
        if isValidMove(ny, nx): y, x = ny, nx
        else: continue 
         
k_pos = chr(ord('A') + x) + str(y + 1)
s_pos = chr(ord('A') + s_x) + str(s_y + 1)

print(k_pos)
print(s_pos)
