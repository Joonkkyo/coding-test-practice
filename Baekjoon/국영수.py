import sys

info_list = []
N = int(input())
for _ in range(N):
    info = sys.stdin.readline().split()
    info_list.append(info)
    
info_list.sort(key=lambda x : (-(int(x[1])), int(x[2]), -(int(x[3])), x[0]))

for info in info_list:
    print(info[0])
