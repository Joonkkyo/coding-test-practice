N = int(input())

for _ in range(N):
    N, M = map(int, input().split())
    queue = list(map(int, input().split()))
    pair_queue = []
    count = 0
    
    for i in range(len(queue)):
        pair_queue.append((queue[i], i))
        
    while pair_queue:
        if pair_queue[0][0] == max(pair_queue)[0]:
            doc = pair_queue.pop(0)
            count += 1
            
            if doc[1] == M:
                print(count)
                break
        else:
            pair_queue.append(pair_queue.pop(0))
