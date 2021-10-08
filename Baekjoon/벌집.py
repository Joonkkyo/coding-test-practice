N = int(input())

num, mul = 0, 1
diff, answer = 1, 1

while num + 1 < N:
    num = 6 * mul
    diff += 1
    mul += diff
    answer += 1
    
print(answer)
