string = input()
word_list = []

for i in range(len(string)):
    word = string[i:]
    word_list.append(word)
    
word_list.sort()
for word in word_list:
    print(word)
