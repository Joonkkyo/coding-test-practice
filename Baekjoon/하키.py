import sys

W, H, X, Y, P = map(int, input().split())
answer = 0

for _ in range(P):
    p_x, p_y = map(int, sys.stdin.readline().split())
    if X <= p_x <= X + W and Y <= p_y <= Y + H:
        answer += 1
        
    elif (X - p_x) ** 2 + (Y + H // 2 - p_y) ** 2 <= (H // 2) ** 2:
        answer += 1
        
    elif (X + W - p_x) ** 2 + (Y + H // 2 - p_y) ** 2 <= (H // 2) ** 2:
        answer += 1
              
print(answer)
    
