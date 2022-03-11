import sys

N = int(input())

for _ in range(N):
    a, b = map(int, sys.stdin.readline().split())
    num_list = []
    
    if a % 10 == 0:
        print(10)
        continue
    
    else:
        temp = a
        while True:
            if  (temp % 10) in num_list:
                break
            
            if a % 10 != 0:
                num_list.append(temp % 10)
                
            temp *= a
            
        print(num_list[b % (len(num_list)) - 1])
