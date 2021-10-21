def solution(priorities, location):
    pair_queue = []
    answer = 0
    for i in range(len(priorities)):
        pair_queue.append((priorities[i], i))
        
    while pair_queue:
        if pair_queue[0][0] == max(pair_queue)[0]:
            doc = pair_queue.pop(0)
            answer += 1
            
            if doc[1] == location:
                print(answer)
                break
        else:
            pair_queue.append(pair_queue.pop(0))
            
    return answer
