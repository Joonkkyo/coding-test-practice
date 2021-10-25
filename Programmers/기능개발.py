def solution(progresses, speeds):
    answer = []
    
    while progresses:
        day = 0 
        count = 0
        while progresses[0] < 100:
            progresses[0] += speeds[0]
            day += 1
        
        if len(progresses) >= 2:
            for i in range(1, len(progresses)):
                progresses[i] += day * speeds[i] 
            
        while progresses and progresses[0] >= 100:
            progresses.pop(0)
            speeds.pop(0)
            count += 1
            
        answer.append(count)
                      
    return answer
