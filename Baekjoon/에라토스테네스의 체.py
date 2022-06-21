N, K = map(int, input().split())
num = [False, False] + [True] * (N - 1)
ans_list = []
count = 0

for i in range(2, N + 1):
    if num[i]:
        ans_list.append(i)
        num[i] = False
        for j in range(i, N + 1, i):
            if num[j]:
                ans_list.append(j)
                num[j] = False

print(ans_list[K - 1])

