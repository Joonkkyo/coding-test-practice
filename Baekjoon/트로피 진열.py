N = int(input())
trophy = []
left, right = 1, 1

for _ in range(N):
    trophy.append(int(input()))
                  
val_l = trophy[0]
for i in range(1, N):
    if val_l == max(val_l, trophy[i]):
        continue
    else:
        val_l = max(val_l, trophy[i])
        left += 1

val_r = trophy[-1] 
for i in range(N - 1, -1, -1):
    if val_r == max(val_r, trophy[i]):
        continue
    else:
        val_r = max(val_r, trophy[i])
        right += 1

print(left)
print(right)
