class Solution:
    def deckRevealedIncreasing(self, deck: List[int]) -> List[int]:
        ordered_deck = sorted(deck)
        answer = []
        answer.append(ordered_deck.pop())
        
        for i in range(len(deck) - 1):
            temp = answer.pop(len(answer) - 1)
            answer.insert(0, temp)
            if ordered_deck:
                answer.insert(0, ordered_deck.pop())
                
        return answer
