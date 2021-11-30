N = int(input())
card = sorted(list(map(int, input().split())))
M = int(input())
check = list(map(int, input().split()))

def binary_search(arr, target, start, end):
    while start <= end:
        mid = (start + end) // 2
        
        if arr[mid] == target:
            return 1
        elif arr[mid] > target:
            end = mid - 1
        else:
            start = mid + 1
    return 0

for num in check:
    print(binary_search(card, num, 0, N - 1), end=" ")
