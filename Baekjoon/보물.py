N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

answer = 0
for i in range(N):
    num1, num2 = min(A), max(B)
    answer += num1 * num2
    A.remove(num1)
    B.remove(num2)
    
print(answer)
