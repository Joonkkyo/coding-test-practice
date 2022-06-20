import sys

N = int(input())
switches = list(map(int, input().split()))
M = int(input())

for _ in range(M):
    gender, num = map(int, sys.stdin.readline().split())
    if gender == 1:
        for i in range(1, N + 1):
            if i % num == 0:
                switches[i - 1] ^= 1
    else:
        switches[num - 1] ^= 1
        start, end = num - 2, num

        while start >= 0 and end <= N - 1:
            if switches[start] == switches[end]:
                switches[start] ^= 1
                switches[end] ^= 1
                start -= 1
                end += 1
            else:
                break

q, r = N // 20, N % 20
for i in range(q):
    for j in range(20):
        print(switches[i * 20 + j], end=' ')
    print()

for i in range(r):
    print(switches[q * 20 + i], end=' ')
