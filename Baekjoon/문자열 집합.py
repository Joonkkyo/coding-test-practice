import sys

N, M = map(int, input().split())
answer = 0
str_set = set()

for _ in range(N):
    str_set.add(sys.stdin.readline())

for _ in range(M):
    if sys.stdin.readline() in str_set:
        answer += 1

print(answer)
