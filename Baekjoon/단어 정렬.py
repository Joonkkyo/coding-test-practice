import sys

N = int(input())
word_list = []

for _ in range(N):
    word_list.append(sys.stdin.readline().rstrip())
    
word_list = set(word_list)
word_list = list(word_list)

word_list = sorted(word_list)
word_list.sort(key=lambda x : len(x))

for word in word_list:
    print(word)
