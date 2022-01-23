import sys

N, K = map(int, input().split())

coins, answer = [], 0
for i in range(N):
    coins.append(int(sys.stdin.readline()))

find_max = False
while K > 0:
    for i in range(len(coins)):
        if coins[i] > K and i > 0:
            find_max = True
            quot = K // coins[i - 1]
            answer += quot
            K -= quot * coins[i - 1]
            
    if not find_max:
        quot = K // coins[len(coins) - 1]
        answer += quot
        K -= quot * coins[len(coins) - 1]

print(answer)
