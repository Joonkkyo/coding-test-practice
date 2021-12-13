N = int(input())
files = []
for _ in range(N):
    file = input()
    files.append(file)
    
if len(files) == 1:
    print(files[0])   

else:
    answer = list(files[0])
    word_len = len(files[0])
    for i in range(N - 1):
        for j in range(word_len):
            if files[i][j] != files[i + 1][j]:
                answer[j] = '?'
                
    print("".join(answer))
