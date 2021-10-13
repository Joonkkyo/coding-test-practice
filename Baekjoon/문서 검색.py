documents = input()
criterion = input()

answer = 0
cur = 0

while cur < len(documents):
    if documents[cur] == criterion[0]:
        if len(documents) - cur >= len(criterion):
            isEqual, count = True, 0
            prev_cur = cur
            
            for i in range(len(criterion)):
                if documents[cur] != criterion[i]: 
                    check = False
                    cur = prev_cur + 1
                    break
                else:
                    count += 1
                    cur += 1
                    
            if isEqual and count == len(criterion): 
                answer += 1             
        else: break
    else: cur += 1
    
print(answer)                
    
