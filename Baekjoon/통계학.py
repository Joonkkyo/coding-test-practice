import sys

N = int(input())
num_list, num_map = [], {}
for _ in range(N):
    num = num_list.append(int(sys.stdin.readline()))
num_list = sorted(num_list)

for num in num_list:
    if num not in num_map: num_map[num] = 1
    else: num_map[num] += 1

num_map = sorted(num_map.items(), reverse=True, key=lambda item: item[1])
if len(num_map) == 1:
    freq = num_map[0][0]
else:
    key_list = [num_map[0][0]]
    for i in range(1, len(num_map)):
        if num_map[i - 1][1] != num_map[i][1]:
            break
        else:
            key_list.append(num_map[i][0]) 
            
    key_list = sorted(key_list)  
    if len(key_list) == 1: freq = key_list[0]
    else: freq = key_list[1]
              
avg = int(round(sum(num_list) / N))
mid = num_list[len(num_list) // 2]
ran = max(num_list) - min(num_list)

print(avg)
print(mid)
print(freq)
print(ran)
