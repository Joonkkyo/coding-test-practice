num_list = list(map(int, input().split()))

if num_list[0] < num_list[1]: prev = True 
else: prev = False

isAscending, stopped = True, False
for i in range(1, len(num_list) - 1):
    if num_list[i] < num_list[i + 1]:
        isAscending = True
    else:
        isAscending = False

    if prev != isAscending:
        print("mixed")
        stopped = True
        break

if isAscending and not stopped: print("ascending") 
elif not isAscending and not stopped: print("descending")
