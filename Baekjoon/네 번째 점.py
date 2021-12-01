dicX, dicY = {}, {}
answerX, answerY = 0, 0
for _ in range(3):
    dx, dy = map(int, input().split())
    if dx not in dicX:
        dicX[dx] = 1
    else:
        dicX[dx] += 1
    
    if dy not in dicY:
        dicY[dy] = 1
    else:
        dicY[dy] += 1
        
for x in dicX:
    if dicX[x] % 2 != 0:
        answerX = x

for y in dicY:
    if dicY[y] % 2 != 0:
        answerY = y
        
print(answerX, answerY)
