import sys

T = int(input())
for _ in range(T):
    n = int(sys.stdin.readline())
    wear_dict = {}
    answer = 1
    
    for _ in range(n):
        wear, type = sys.stdin.readline().split()
        if type not in wear_dict.keys():
            wear_dict[type] = []
        wear_dict[type].append(wear)
        
    for key in wear_dict.keys():
        answer *= len(wear_dict[key]) + 1
        
    print(answer - 1)
