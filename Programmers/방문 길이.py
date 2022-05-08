def solution(dirs):
    d = [(1, 0), (-1, 0), (0, 1), (0, -1)]
    pos_dict = {}
    answer = 0
    y, x = 0, 0
    
    for i in range(len(dirs)):
        if dirs[i] == 'U':
            ny, nx = y + d[0][0], x + d[0][1]
            
        if dirs[i] == 'D':
            ny, nx = y + d[1][0], x + d[1][1]
            
        if dirs[i] == 'R':
            ny, nx = y + d[2][0], x + d[2][1]
            
        if dirs[i] == 'L':
            ny, nx = y + d[3][0], x + d[3][1]
            
        if not (-5 <= ny <= 5 and -5 <= nx <= 5):
            continue
            
        if ((y, x), (ny, nx)) not in pos_dict.keys() and ((ny, nx), (y, x)) not in pos_dict.keys():
            pos_dict[((y, x), (ny, nx))] = 1
            answer += 1

        y, x = ny, nx
        
    return answer
