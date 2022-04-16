def isPossible(queen, row):
    for i in range(row):
        if queen[i] == queen[row]:  
            return False
        
        if abs(queen[i] - queen[row]) == row - i:
            return False
        
    return True

def solve(queen, row):
    answer = 0
    n = len(queen)

    if n == row:
        return 1

    for col in range(n):
        queen[row] = col
        if isPossible(queen, row):
            answer += solve(queen, row + 1)

    return answer

def solution(n):
    queen = [0] * n
    return solve(queen, 0)
