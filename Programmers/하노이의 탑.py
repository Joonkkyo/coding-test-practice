def hanoi(num, start, to, mid, ans):
    if num == 1:
        ans.append([start, to])
        return
    
    hanoi(num - 1, start, mid, to, ans)
    ans.append([start, to])
    hanoi(num - 1, mid, to, start, ans)

    
def solution(n):
    answer = []
    hanoi(n, 1, 3, 2, answer)
    return answer
