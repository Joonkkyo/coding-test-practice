import sys

while True:
    CD1, CD2 = [], []
    N, M = map(int, sys.stdin.readline().split())    
    if N == 0 and M == 0:
        break
    
    for _ in range(N):
        CD1.append(int(sys.stdin.readline()))
    
    for _ in range(M):
        CD2.append(int(sys.stdin.readline()))
    
    print(len(set(CD1) & set(CD2)))
