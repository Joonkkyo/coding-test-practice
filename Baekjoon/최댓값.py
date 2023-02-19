import sys

arr = []
for _ in range(9):
    arr.append(list(map(int, sys.stdin.readline().split())))

max_val, y, x = 0, 0, 0
for i in range(9):
    for j in range(9):
        if arr[i][j] > max_val: 
            y, x = i, j
            max_val = arr[i][j]

print(max_val)
print(y + 1, x + 1)
