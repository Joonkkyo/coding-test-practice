def rotate_matrix(mat):
    n = len(mat)
    ret = [[0] * n for _ in range(n)]
    
    for i in range(n):
        for j in range(n):
            ret[j][n - i - 1]  = mat[i][j]
            
    return ret
            
    
def is_solved(mat):
    m = len(mat) // 3
    for i in range(m, m * 2):
        for j in range(m, m * 2):
            if mat[i][j] != 1:
                return False
            
    return True
        
            
def solution(key, lock):
    answer = True
    n, m = len(key), len(lock)
    new_lock = [[0] * m * 3 for _ in range(m * 3)]
    
    for i in range(m):
        for j in range(m):
            new_lock[m + i][m + j] = lock[i][j]
            
    temp_key = key
    for _ in range(4):
        temp_key = rotate_matrix(temp_key)
        
        for i in range(m * 3 - n):
            for j in range(m * 3 - n):
                for y in range(n):
                    for x in range(n):
                        new_lock[i + y][j + x] += temp_key[y][x]
                
                if is_solved(new_lock):
                    return True
                
                else:
                    for y in range(n):
                        for x in range(n):
                            new_lock[i + y][j + x] -= temp_key[y][x]
                
    else: 
        return False
