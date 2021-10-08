import sys

N = int(input())
rope = []

for _ in range(N):
    rope.append(int(sys.stdin.readline()))

rope.sort(reverse=True)
answer = rope[0]

for i in range(1, N):
    answer = max(answer, rope[i] * (i + 1))

print(answer)
