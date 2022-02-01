T = int(input())

dy = [1, 0, -1, 0]
dx = [0, 1, 0, -1]

def change_dir(c, d):
    if c == 'L':
        d -= 1
    else:
        d += 1
        
    return (d % 4)    

for _ in range(T):
    direction = 0    
    y, x = 0, 0
    command = list(input())
    points_y, points_x = [0], [0]
    
    for i in range(len(command)):
        if command[i] == 'F':
            y += dy[direction]
            x += dx[direction]
            points_y.append(y)
            points_x.append(x)
            
        elif command[i] == 'B':
            y -= dy[direction]
            x -= dx[direction]
            points_y.append(y)
            points_x.append(x)
            
        else:
            direction = change_dir(command[i], direction)

    width = abs(max(points_x) - min(points_x))
    height = abs(max(points_y) - min(points_y))

    print(width * height)
            
            
