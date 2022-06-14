S = input()
word_set = set()

for i in range(len(S)):
    for j in range(len(S) - i + 1):
        word = S[j:i + j]
        word_set.add(word)

print(len(word_set))
