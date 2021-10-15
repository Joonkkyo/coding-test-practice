X = int(input())

for i in range(1, 10000):
    if (i - 1) * i < 2 * X <= i * (i + 1):
        target = i
        break
    
idx = int(X - (target - 1) * target / 2)
if target % 2 == 0:
    print(str(idx) + '/' + str(target - idx + 1))
else:
    print(str(target - idx + 1) + '/' + str(idx))
