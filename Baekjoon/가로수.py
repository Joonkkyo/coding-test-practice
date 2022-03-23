import sys

def GCD(num1, num2):
    while num2 != 0:
        num1, num2 = num2, num1 % num2
    return num1
        
        
N = int(input())
trees, diff_arr = [], []
answer = 0
for _ in range(N):
    trees.append(int(sys.stdin.readline()))
    
trees.sort()
for i in range(len(trees) - 1):
    diff_arr.append(trees[i + 1] - trees[i])
    
gcd = diff_arr[0]
for i in range(1, len(diff_arr)):
    gcd = GCD(gcd, diff_arr[i])
    
for i in range(len(diff_arr)):
    answer += diff_arr[i] // gcd - 1
    
print(answer)
