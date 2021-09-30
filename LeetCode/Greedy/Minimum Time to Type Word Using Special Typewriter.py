class Solution:
    def minTimeToType(self, word: str) -> int:
        dist, answer = 0, 0
        
        if abs(ord(word[0]) - ord('a')) > 13:
            answer += 26 - abs(ord(word[0]) - ord('a'))
        else:
            answer += abs(ord(word[0]) - ord('a'))
            
        for i in range(len(word) - 1):
            diff = abs(ord(word[i]) - ord(word[i + 1]))
            
            if diff > 13: dist = 26 - diff
            else: dist = diff
            answer += dist
        answer += len(word)
        
        return answer
