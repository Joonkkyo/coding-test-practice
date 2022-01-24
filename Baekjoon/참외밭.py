import sys

K = int(input())
w, h = 0, 0

dir_list, len_list = [], []
for i in range(6):
    dir, len = map(int, sys.stdin.readline().split())
    if dir == 3 or dir == 4:
        h = max(h, len)
    if dir == 1 or dir == 2:
        w = max(w, len)
    dir_list.append(dir)
    len_list.append(len)

w_idx, h_idx = 0, 0
for i in range(6):
    if (dir_list[i] == 3 or dir_list[i] == 4) and len_list[i] == h: h_idx = i
    if (dir_list[i] == 1 or dir_list[i] == 2) and len_list[i] == w: w_idx = i
    

sub_h = len_list[(w_idx + 3) % 6]
sub_w = len_list[(h_idx + 3) % 6]
answer = K * (w * h - sub_w * sub_h)
