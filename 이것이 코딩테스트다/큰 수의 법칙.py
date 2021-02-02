n, m, k = map(int, input().split())
data = list(map(int, input().split()))
answer = 0

data.sort()
first_num = data[n - 1]
second_num = data[n - 2]

count = 0
for i in range(m):
    if count == k:
        answer += second_num
        count = 0
        continue
    answer += first_num
    count += 1

print(answer)
