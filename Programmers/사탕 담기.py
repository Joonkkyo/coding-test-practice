from itertools import combinations

def solution(m, weights):
    weights.sort()
    n = len(weights)
    answer = 0
    
    for i in range(n):
        sum_weights = 0
        for comb in combinations(weights, i):
            sum_weights = sum(comb)
            if sum_weights == m:
                answer += 1
    
    return answer
