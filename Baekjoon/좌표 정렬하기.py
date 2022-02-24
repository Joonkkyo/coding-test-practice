import sys

N = int(input())
point_list = []

for _ in range(N):
    point = tuple(map(int, sys.stdin.readline().split()))
    point_list.append(point)
    
point_list.sort(key=lambda x : (x[0], x[1]))
for point in point_list:
    print(point[0], point[1])
