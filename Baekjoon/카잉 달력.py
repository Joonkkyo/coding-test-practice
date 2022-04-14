from math import lcm
import sys
        
T = int(input())
for _ in range(T):
    M, N, x, y = map(int, sys.stdin.readline().split())
    limit = lcm(M, N)
    
    while x <= limit:
        if (x - y) % N == 0:
            print(x)
            break
        x += M
    else:
        print(-1)
