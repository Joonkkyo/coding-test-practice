import sys

T = int(input())
for _ in range(T):
    phone_list = []
    n = int(input())
    for i in range(n):
        phone_list.append(sys.stdin.readline().rstrip())
    phone_list.sort()
    
    breaker = False
    for i in range(len(phone_list) - 1):
        comp = phone_list[i]
        for j in range(i + 1, len(phone_list)):
            str_len = len(comp)
            if comp[0] == phone_list[j][0]:
                if phone_list[j][:str_len] == comp:
                    print("NO")
                    breaker = True
                    break
            else: 
                break
            
        if breaker:
            break
        
    if not breaker: print("YES")
    
