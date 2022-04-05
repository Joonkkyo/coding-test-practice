N = int(input())
num_list = list(map(int, input().split()))
stack = []
answer = [-1] * N

for i in range(len(num_list)):
    while stack and stack[-1][0] < num_list[i]:
        num, idx = stack.pop()
        answer[idx] = num_list[i]
        
    stack.append((num_list[i], i))
    
print(*answer)
