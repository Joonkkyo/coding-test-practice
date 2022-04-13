def solution(skill, skill_trees):
    answer = 0
    skill_dict = {}
    for i in range(len(skill)):
        skill_dict[skill[i]] = i
        
    for skill_tree in skill_trees:
        idx_arr = []
        for skill in skill_tree:
            if skill in skill_dict.keys():
                idx_arr.append(skill_dict[skill])
                
        temp = [i for i in range(len(idx_arr))]
        if idx_arr == temp: 
            answer += 1
        
    return answer
