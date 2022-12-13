import sys

N, M = map(int, input().split())
idx_dict = {}
arr, questions = [], [] 

sorted_arr = sorted([int(sys.stdin.readline()) for _ in range(N)])
questions = [int(sys.stdin.readline()) for _ in range(M)]

for i in range(N):
    if sorted_arr[i] not in idx_dict.keys():
        idx_dict[sorted_arr[i]] = i

for question in questions:
    if question not in idx_dict.keys():
        print(-1)
    else:
        print(idx_dict[question])
