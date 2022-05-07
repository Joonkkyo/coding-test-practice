from collections import defaultdict

def solution(board, nums):
    row_dict, col_dict = defaultdict(int), defaultdict(int)
    r_diag_cnt, l_diag_cnt = 0, 0
    pos_dict, visited = {}, []
    n = len(board)
    answer = 0
    
    for i in range(n):
        for j in range(n):
            pos_dict[board[i][j]] = (i, j)
        
    for num in nums:
        visited.append(pos_dict[num])
        
    for y, x in visited:
        row_dict[y] += 1
        col_dict[x] += 1
        
        if y == x:
            r_diag_cnt += 1
            
        if y + x == n - 1:
            l_diag_cnt += 1
    
    for key, val in row_dict.items():
        if val == n:
            answer += 1
            
    for key, val in col_dict.items():
        if val == n:
            answer += 1
            
    if r_diag_cnt == n:
        answer += 1
        
    if l_diag_cnt == n:
        answer += 1
    
    return answer
