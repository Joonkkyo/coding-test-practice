from itertools import permutations

N = int(input())
num_list = list(map(int, input().split()))
perm_list = list(permutations(num_list, N))
answer = 0

def solve(list):
    total = 0
    for i in range(len(list) - 1):
        total += abs(list[i] - list[i + 1])
    return total

for perm in perm_list:
    answer = max(answer, solve(perm))

print(answer)
