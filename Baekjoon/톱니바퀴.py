from collections import deque


def rotation(n, d):
    if d == 1:
        gear_list[n].appendleft(gear_list[n].pop())
    else:
        gear_list[n].append(gear_list[n].popleft())


gear_list = []
for _ in range(4):
    gear_list.append(deque(list(map(int, input()))))

K = int(input())
for _ in range(K):
    gear_num, direction = map(int, input().split())
    cur = gear_num - 1
    left, right = cur - 1, cur + 1
    rotate_idx = []
    tmp_dir_1 = direction
    tmp_dir_2 = direction

    while left >= 0:
        if gear_list[left][2] != gear_list[cur][6]:
            rotate_idx.append((left, tmp_dir_1 * -1))
            cur = left
            left -= 1
            tmp_dir_1 *= -1
        else:
            break

    cur = gear_num - 1
    while right <= 3:
        if gear_list[cur][2] != gear_list[right][6]:
            rotate_idx.append((right, tmp_dir_2 * -1))
            cur = right
            right += 1
            tmp_dir_2 *= -1
        else:
            break

    for idx, dir in rotate_idx:
        rotation(idx, dir)

    rotation(gear_num - 1, direction)

answer = 0
for i in range(4):
    if gear_list[i][0] == 1:
        answer += 2 ** i

print(answer)
