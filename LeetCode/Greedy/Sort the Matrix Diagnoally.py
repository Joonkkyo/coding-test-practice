class Solution:
    def diagonalSort(self, mat: List[List[int]]) -> List[List[int]]:
        row_len, col_len = len(mat[0]), len(mat)
        col = 0

        for i in range(row_len):
            temp_arr = []
            idx_list = []
            temp_i = i
            col = 0

            while col < col_len and temp_i < row_len:
                idx_list.append((col, temp_i))
                temp_arr.append(mat[col][temp_i])
                temp_i += 1 
                col += 1
            temp_arr.sort()
        
            for i in range(len(idx_list)):
                mat[idx_list[i][0]][idx_list[i][1]] = temp_arr[i]
              
        for i in range(col_len - 1):
            temp_arr = []
            idx_list = []
            temp_i = 0
            col = i + 1
            while col < col_len and temp_i < row_len:
                print(col, temp_i)
                idx_list.append((col, temp_i))
                temp_arr.append(mat[col][temp_i])
                temp_i += 1 
                col += 1
            temp_arr.sort()
            
            for i in range(len(idx_list)):
                mat[idx_list[i][0]][idx_list[i][1]] = temp_arr[i]
            
        return mat
