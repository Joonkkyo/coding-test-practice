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
    
    idx_1, idx_2 = 0, 0
    answer = 0
    
    while idx_1 != N and idx_2 != M:   
        if CD1[idx_1] == CD2[idx_2]:
            idx_1 += 1
            idx_2 += 1
            answer += 1
        
        elif CD1[idx_1] < CD2[idx_2]:
            idx_1 += 1
            
        else:
            idx_2 += 1
            
    print(answer)
