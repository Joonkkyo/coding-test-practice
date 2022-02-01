pieces = list(map(int, input().split()))
idx = 0

def change(arr, idx):
    if arr[idx] > arr[idx + 1]:
        temp = arr[idx]
        arr[idx] = arr[idx + 1]
        arr[idx + 1] = temp
        for num in arr:
            print(num, end=" ")
        print()


def isAnswer(arr):
    if arr == [1, 2, 3, 4, 5]:
        return False
    else:
        return True
    
    
while isAnswer(pieces):
    change(pieces, idx)
    idx += 1
    idx %= 4
