from itertools import combinations

def solution(n):
    a = [False, False] + [True] * (n - 1)
    primes = []
    answer = 0

    for i in range(2, n + 1):
        if a[i]:
            primes.append(i)
            for j in range(2 * i, n + 1, i):
                a[j] = False
    
    for comb in combinations(primes, 3):
        if sum(comb) == n:
            answer += 1
            
    return answer
