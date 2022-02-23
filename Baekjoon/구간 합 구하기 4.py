import sys

N, M = map(int, input().split())
num_list = list(map(int, input().split()))
sum_list = []
sum = 0
for i in range(len(num_list)):
    sum += num_list[i]
    sum_list.append(sum)
  
for _ in range(M):
    i, j = map(int, sys.stdin.readline().split())
    if i == 1: 
        print(sum_list[j - 1])
    elif i == j: 
        print(num_list[j - 1])
    else: 
        print(sum_list[j - 1] - sum_list[i - 2])
