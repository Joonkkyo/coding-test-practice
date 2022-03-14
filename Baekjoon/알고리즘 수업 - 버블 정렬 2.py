def bubble_sort(arr, target):
    count = 0
    for i in range(len(arr) - 1):
        for j in range(len(arr) - i - 1):
            if count == target:
                break
            
            if arr[j] > arr[j + 1]:
                temp = arr[j]
                arr[j] = arr[j + 1]
                arr[j + 1] = temp
                count += 1
                
    if target > count:
        print(-1)
    else:
        for num in arr:
            print(num, end=" ")

A, K = map(int, input().split())
num_list = list(map(int, input().split()))
bubble_sort(num_list, K)
