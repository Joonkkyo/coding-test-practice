import sys

N = int(input())
point_dic = {}
point_list = list(map(int, sys.stdin.readline().split()))    
temp_list = sorted(list(set(point_list)))

for i in range(len(temp_list)):
    point_dic[temp_list[i]] = i
    
for point in point_list:
    print(point_dic[point], end=" ")
