word = input()
word_list = []
for i in range(1, len(word) - 1):
    for j in range(i + 1, len(word)):
        temp1 = word[:i]
        temp2 = word[i:j]
        temp3 = word[j:]

        temp1, temp2, temp3 = temp1[::-1], temp2[::-1], temp3[::-1]
        word_list.append(temp1 + temp2 + temp3)
    
word_list.sort()
print(word_list[0])
