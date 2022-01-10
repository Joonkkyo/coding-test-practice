T = int(input())

for _ in range(T):
    start_x, start_y, end_x, end_y = map(int, input().split())
    n = int(input())
    answer = 0
    
    for _ in range(n):
        x, y, r = map(int, input().split())
        d1 = ((start_x - x) ** 2 + (start_y - y) ** 2) ** 0.5
        d2 = ((end_x - x) ** 2 + (end_y - y) ** 2) ** 0.5
        
        if (d1 > r and d2 < r) or (d1 < r and d2 > r):
            answer += 1
            
    print(answer)
