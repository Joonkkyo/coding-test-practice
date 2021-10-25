import itertools

def solution(k, dungeons):
    answer = 0
    comb = list(itertools.permutations(dungeons))
    
    for lists in comb:
        count = 0
        remain = k
        
        for i in range(len(dungeons)):
            if lists[i][0] <= remain:
                remain -= lists[i][1]
                count += 1
            else:
                continue
        answer = max(count, answer)
        
    return answer
