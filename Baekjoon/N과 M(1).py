def solve(depth):
    if depth == M:
        for i in range(M):
            print(num_arr[i], end=" ")
        print()
        return
    
    for i in range(1, N + 1):
        if not visited[i]:
            num_arr[depth] = i
            visited[i] = True
            solve(depth + 1)
            visited[i] = False


N, M = map(int, input().split())
visited = [False] * (N + 1)
num_arr = [0] * 10            
solve(0)
