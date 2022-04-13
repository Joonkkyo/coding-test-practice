def solution(id_list, report, k):
    answer = []
    report = list(set(report))
    count_dict, report_dict = {}, {}
    
    for id in id_list:
        count_dict[id] = 0
        report_dict[id] = []
        
    for r in report:
        reporter, user = r.split(' ')
        count_dict[user] += 1
        report_dict[reporter].append(user)
            
    for key, val in report_dict.items():
        count = 0
        for user in val:
            if count_dict[user] >= k:
                count += 1
        answer.append(count)

    return answer
