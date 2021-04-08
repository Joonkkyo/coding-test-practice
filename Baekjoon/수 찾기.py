def binary_search(arr, target):
    start = 0
    end = len(arr) - 1

    while start <= end:
        mid = (start + end) // 2

        if arr[mid] == target: 
            return 1
        elif arr[mid] > target:
            end = mid - 1
        else:
            start = mid + 1
    return 0


N = int(input())
arr_1 = sorted(list(map(int, input().split())))

M = int(input())
arr_2 = list(map(int, input().split()))

for i in range(M):
    print(binary_search(arr_1, arr_2[i]))
