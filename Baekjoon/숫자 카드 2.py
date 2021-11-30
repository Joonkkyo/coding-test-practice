import sys

N = int(input())
card = sorted(list(map(int, sys.stdin.readline().split())))
M = int(input())
check = list(map(int, sys.stdin.readline().split()))
cardDic = {}

for c in card:
    if c not in cardDic:
        cardDic[c] = 1
    else:
        cardDic[c] += 1
        
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
    if binary_search(card, num, 0, N - 1):
        print(cardDic[num], end=" ")
    else:
        print(0, end=" ")
