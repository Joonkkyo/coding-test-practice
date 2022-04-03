def solution(clothes):
    clothes_dict = {}
    answer = 1
    
    for i in range(len(clothes)):
        if clothes[i][1] not in clothes_dict.keys():
            clothes_dict[clothes[i][1]] = [clothes[i][0]]
        else:
            clothes_dict[clothes[i][1]].append(clothes[i][0])
    
    for key, value in clothes_dict.items():
        answer *= len(value) + 1
        
    return answer - 1
