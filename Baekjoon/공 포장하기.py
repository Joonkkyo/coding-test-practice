R, G, B = map(int, input().split())
answer = 0

R_q, G_q, B_q = R // 3, G // 3, B // 3
R_r, G_r, B_r = R % 3, G % 3, B % 3
answer += R_q + G_q + B_q

while R_r > 0 and G_r > 0 and B_r > 0:
    R_r -= 1
    G_r -= 1
    B_r -= 1
    answer += 1

if R_r == 2:
    answer += 1
    R_r = 0
if B_r == 2:
    answer += 1
    B_r = 0
if G_r == 2:
    answer += 1
    G_r = 0
if R_r + B_r + G_r > 0:
    answer += 1

print(answer)
