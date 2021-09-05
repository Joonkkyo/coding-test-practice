n = int(input())

hours, minutes, seconds = 24, 60, 60
answer = 0

for i in range(n + 1):
    for j in range(minutes):
        for k in range(seconds):
            if '3' in str(i) + str(j) + str(k):
                answer += 1
                
print(answer)
