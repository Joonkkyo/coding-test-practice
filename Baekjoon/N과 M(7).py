def solve(depth, num_arr):
    if depth == M:
        for i in range(M):
            print(answer[i], end=" ")
        print()
        return
    
    for num in num_arr:
        answer[depth] = num
        solve(depth + 1, num_arr)


N, M = map(int, input().split())
num_arr = list(map(int, input().split()))
answer = [0] * 10001
solve(0, sorted(num_arr))
