S = input()

zero, one = 0, 0
flag = False
for i in range(len(S) - 1):
    if S[i] != S[i + 1]:
        if S[i] == '0':
            zero += 1
        else:
            one += 1
            
        if i == len(S) - 2:
            if S[i + 1] == '0':
                zero += 1
            else:
                one += 1
        flag = False
        
    else:
        flag = True
            
if flag:
    if S[-1] == '0':
        zero += 1
    else:
        one += 1

print(min(one, zero))
