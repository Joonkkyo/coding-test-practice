from collections import deque

N = int(input())
cards = deque([i for i in range(1, N + 1)])
answer = []

while len(cards) > 1:
    answer.append(cards.popleft())
    cards.append(cards.popleft())

for num in answer:
    print(num, end=" ")
 
print(cards[0])
