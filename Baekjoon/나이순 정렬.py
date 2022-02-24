import sys

info_list = []
N = int(input())
for _ in range(N):
    info = tuple(sys.stdin.readline().split())
    info_list.append(info)
    
info_list.sort(key=lambda x : int(x[0]))

for info in info_list:
    print(info[0], info[1])
