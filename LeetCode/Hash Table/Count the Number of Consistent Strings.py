class Solution:
    def countConsistentStrings(self, allowed: str, words: List[str]) -> int:
        allowed = set(allowed)
        answer = 0
        
        for word in words:
            for letter in word:
                if letter not in allowed:
                    answer += 1
                    break
        
        return len(words) - answer
