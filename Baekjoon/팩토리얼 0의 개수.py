N = int(input())
two_cnt, five_cnt = 0, 0
for i in range(1, N + 1):
    while i % 2 == 0:
        i //= 2
        two_cnt += 1
    while i % 5 == 0:
        i //= 5
        five_cnt += 1
        
print(min(two_cnt, five_cnt))
