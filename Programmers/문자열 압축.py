def solution(s):
    if len(s) == 1:
        return 1
    
    answer = 1e3
    for i in range(1, (len(s) // 2) + 1):
        word_list = []
        count = 0
        pattern = s[:i]
        string = ""
        for j in range(0, len(s), i):
            word_list.append(s[j:j + i])
        
        for k in range(len(word_list)):
            if pattern == word_list[k]:
                count += 1
            else:
                if count >= 2:
                    string += str(count) + pattern
                else:
                    string += pattern
                pattern = word_list[k]
                count = 1   
            
            if k == len(word_list) - 1:
                if count >= 2:
                    string += str(count) + pattern
                else:
                    string += pattern 

        answer = min(answer, len(string))

    return answer
