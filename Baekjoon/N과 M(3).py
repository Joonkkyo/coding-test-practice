def check(num1, num2):
    if num1 < num2:
        return True
    return False

def solve(depth):
    if depth == M:
        for i in range(M):
            print(num_arr[i], end=" ")
        print()
        return
    
    for i in range(1, N + 1):
        num_arr[depth] = i
        solve(depth + 1)


N, M = map(int, input().split())
num_arr = [0] * 10            
solve(0)
