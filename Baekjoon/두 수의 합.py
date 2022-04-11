from reprlib import aRepr
import sys

N = int(sys.stdin.readline().strip())
arr = list(map(int, sys.stdin.readline().split()))
x = int(sys.stdin.readline().strip())

left, right = 0, N - 1
arr.sort()
answer = 0

while left < right:
    result = arr[left] + arr[right]
    if result == x:
        answer += 1
        
    if result < x:
        left += 1
    else:
        right -= 1
        
print(answer)
