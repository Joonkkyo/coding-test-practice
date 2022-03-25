def check(num1, num2):
    if num1 < num2:
        return True
    return False


def solve(depth, num_arr):
    if depth == M:
        for i in range(M):
            print(answer[i], end=" ")
        print()
        return
    
    for num in num_arr:
        if not visited[num]:
            if depth == 0 or check(answer[depth - 1], num):
                answer[depth] = num
                visited[num] = True
                solve(depth + 1, num_arr)
                visited[num] = False


N, M = map(int, input().split())
num_arr = list(map(int, input().split()))
visited = [False] * 10001
answer = [0] * 10001
solve(0, sorted(num_arr))
