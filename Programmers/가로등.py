def solution(l, v):
    answer = 0
    diff_list = []
    v.sort()
    if 0 not in v:
        diff_list.append(v[0])

    if l not in v:
        diff_list.append(l - v[-1])

    for i in range(len(v) - 1):
        diff = v[i + 1] - v[i]
        if diff % 2 == 0: diff_list.append(diff // 2)
        else: diff_list.append(diff // 2 + 1)

    return max(diff_list)
