N = input()
num_dict = {}
answer = 1
for i in range(10):
    num_dict[str(i)] = 1

for num in N:
    if num_dict[num] == 0:
        if num == '6' or num == '9':
            if num_dict['6'] + num_dict['9'] == 0:
                for i in range(9):
                    num_dict[str(i)] += 1
                answer += 1
                continue
            
            elif num_dict['6'] > 0 and num_dict['9'] == 0:
                num_dict['6'] -= 1
            elif num_dict['9'] > 0 and num_dict['6'] == 0:
                num_dict['9'] -= 1
            continue
                
        for i in range(10):
            num_dict[str(i)] += 1
        answer += 1
    
    num_dict[num] -= 1

print(answer)
