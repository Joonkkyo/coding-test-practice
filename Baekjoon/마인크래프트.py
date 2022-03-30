import sys

N, M, B = map(int, sys.stdin.readline().split())
height_dic = {}
for i in range(N):
    board = list(map(int, sys.stdin.readline().split()))
    for height in board:
        if height in height_dic.keys(): 
            height_dic[height] += 1
        else:
            height_dic[height] = 1

ans_height, ans_time = 0, int(1e10)
for h in range(257):
    total_time, block = 0, 0
    for key in height_dic.keys():
        if key > h:
            total_time += (key - h) * height_dic[key] * 2
            block += (key - h) * height_dic[key]
        else:
            total_time += (h - key) * height_dic[key]
            block -= (h - key) * height_dic[key]
   
    if B + block < 0:
        continue
    
    if total_time <= ans_time:
        ans_time = total_time
        ans_height = h
        
print(ans_time, ans_height)
