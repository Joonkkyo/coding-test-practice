import sys

def find(x):
    if parent[x] == x:
        return x
    else: 
        parent[x] = find(parent[x])
        return parent[x]


def union(x, y):
    x = find(x)
    y = find(y)
    
    if x < y:
        parent[y] = x
    else:
        parent[x] = y
        
        
sys.setrecursionlimit(10**9)    
n, m = map(int, input().split())
parent = [i for i in range(n + 1)]
for i in range(m):
    op, a, b = map(int, sys.stdin.readline().split())
    
    if op == 0:
        union(a, b)
    else:
        if find(a) == find(b): 
            print("YES")
        else:
            print("NO")
