import sys

def find(x):
    if parent[x] == x:
        return x
    else: 
        parent[x] = find(parent[x])
        return find(parent[x])


def union(x, y):
    x = find(x)
    y = find(y)
    
    if x < y:
        parent[y] = x
    else:
        parent[x] = y
        
        
N, M = map(int, input().split())
truth_list = list(map(int, input().split()))[1:]
parent = [i for i in range(N + 1)]
answer = 0
party_list = []

for _ in range(M):
    possible = True
    party = list(map(int, sys.stdin.readline().split()))[1:]
    party_list.append(party)
    if len(party) >= 2:
        for i in range(len(party) - 1):
            union(party[i], party[i + 1])

for party in party_list:
    possible = True
    for people in party:
        for truth in truth_list:
            if find(people) == find(truth):
                possible = False
                break
            
    if possible: answer += 1  
    
print(answer)
