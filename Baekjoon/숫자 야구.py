from itertools import permutations
import sys

N = int(input())
nums = [i for i in range(1, 10)]
total = set()
for p in permutations(nums, 3):
    n = str(p[0]) + str(p[1]) + str(p[2])
    total.add(int(n))
    
for _ in range(N):
    num, S, B = map(int, sys.stdin.readline().split())
    temp = set()
    num = str(num)
    
    for p in total:
        p = str(p)
        s, b = 0, 0
        for i in range(3):
            if p[i] == num[i]:
                s += 1
            elif p[i] != num[i] and num[i] in p:
                b += 1
                
        if not (s == S and b == B):
            temp.add(int(p))
            
    total -= temp
    
print(len(total))
            
