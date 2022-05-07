def solution(s):
    stack = []
    flag = False
    
    for c in s:
        if c == '(':
            stack.append(c)
            flag = True
        else:
            if stack and stack[-1] == '(' and c == ')':
                stack.pop()

        if not flag:
            return False

    return False if stack else True
