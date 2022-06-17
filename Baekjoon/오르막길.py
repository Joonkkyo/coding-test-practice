N = int(input())
heights = list(map(int, input().split()))
val_list = []
val = 0

for i in range(N - 1):
    if heights[i + 1] - heights[i] > 0:
        val += heights[i + 1] - heights[i]
    else:
        val_list.append(val)
        val = 0

val_list.append(val)
print(max(val_list))
