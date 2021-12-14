w, h = map(int, input().split())
x, y = map(int, input().split())
t = int(input())
dx, dy = 1, 1
x_arr, y_arr = [], []

for _ in range(w * 2):
    nx = x + dx
    
    if nx == 0 or nx == w:
        dx *= -1
    
    x = nx
    x_arr.append(x)
    
for _ in range(h * 2):
    ny = y + dy
    
    if ny == 0 or ny == h:
        dy *= -1
    
    y = ny
    y_arr.append(y)

print(x_arr[t % (w * 2) - 1], y_arr[t % (h * 2) - 1])
