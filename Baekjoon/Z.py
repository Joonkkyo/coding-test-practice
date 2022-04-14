def solve(y, x, n):
    global answer
    if y == r and x == c:
        print(answer)
        exit()
    
    if n == 1:
        answer += 1
        return
    
    if not (y <= r < y + n and x <= c < x + n):
        answer += n ** 2
        return
        
    solve(y, x, n // 2)
    solve(y, x + n // 2, n // 2)
    solve(y + n // 2, x, n // 2)
    solve(y + n // 2, x + n // 2, n // 2)
    
    
N, r, c = map(int, input().split())
answer = 0
solve(0, 0, 2 ** N)
print(answer)
