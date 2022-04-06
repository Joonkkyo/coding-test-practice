string = input()
stack = []
push_stack = True
answer = ""

for ch in string:
    if ch == '<':
        while stack:
            answer += stack.pop()
        push_stack = False
        answer += ch
        continue
    
    elif ch == '>':
        push_stack = True
        answer += ch
        continue
    
    if push_stack:
        if ch == ' ':
            while stack:
                answer += stack.pop()
            answer += ch
        else:
            stack.append(ch)
    else:
        answer += ch      

while stack:
    answer += stack.pop()
    
print(answer)
