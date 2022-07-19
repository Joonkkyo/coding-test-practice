word_arr, answer = [], ''
max_len = 0

for _ in range(5):
    word = list(input())
    word_arr.append(word)
    max_len = max(max_len, len(word))

for i in range(max_len):
    for j in range(5):
        try:
            answer += word_arr[j][i]
        except:
            pass

print(answer)
