from collections import deque

N = int(input())
cards = [i for i in range(1, N + 1)]
cards = deque(cards)

if len(cards) == 1: print(cards[0])
else:
    while True:
        cards.popleft()
        if len(cards) == 1:
            break
        
        cards.append(cards.popleft())
    
    print(cards[0])
