from collections import Counter
import sys

N = int(input())

num_list = []
for _ in range(N):
    num = int(sys.stdin.readline())
    num_list.append(num)

ans_list = Counter(num_list).most_common()
ans_list.sort(key=lambda x: (-x[1], x[0]))
print(ans_list[0][0])
