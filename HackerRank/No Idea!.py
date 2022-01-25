# Enter your code here. Read input from STDIN. Print output to STDOUT
n, m = map(int, input().split())
arr = list(map(int, input().split()))
A = set(map(int, input().split()))
B = set(map(int, input().split()))
answer = 0

for i in range(n):
    if arr[i] in A: answer += 1
    elif arr[i] in B: answer -= 1
        
print(answer)
