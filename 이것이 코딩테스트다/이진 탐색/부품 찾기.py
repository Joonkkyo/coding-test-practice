def binary_search(arr, target, start, end):
    while start <= end:
        mid = (start + end) // 2
        if arr[mid] == target:
            return "yes"
        elif arr[mid] > target:
            end = mid - 1
        else:
            start = mid + 1
    return "no"
        
N = int(input())
num = sorted(list(map(int, input().split())))
M = int(input())
check = list(map(int, input().split()))

for i in range(M):
    print(binary_search(num, check[i], 0, N - 1), end=' ')
    
    
    
