class Solution:
    def commonChars(self, words: List[str]) -> List[str]:
        criterion = Counter(words[0])
        answer = ""
        
        for i in range(1, len(words)):
            criterion = criterion & Counter(words[i])
            
        for key, value in criterion.items():
            answer += key * value
            
        return list(answer)
