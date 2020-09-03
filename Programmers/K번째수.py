def solution(array, commands) :
    answer = []
    com_num = len(commands)
    for i in range(com_num) :
        first = commands[i][0]
        last = commands[i][1]
        idx = commands[i][2]
        arr = array[first - 1:last]
        arr.sort()
        ans = arr[idx - 1]
        answer.append(ans)
        return answer