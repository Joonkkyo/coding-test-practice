point = input()

row = int(point[1])
col = ord(point[0]) - ord('a') + 1
answer = 0

steps = [(2, 1), (2, -1), (-2, 1), (-2, -1), (1, 2), (1, -2), (-1, 2), (-1, -2)]

for step in steps:
    next_row = row + step[0]
    next_col = col + step[1]
    
    if 1 <= next_row <= 8 and 1 <= next_col <= 8:
        answer += 1

print(answer)
