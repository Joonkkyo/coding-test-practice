class Solution:
    def findAndReplacePattern(self, words: List[str], pattern: str) -> List[str]:
        def parsePattern(string: str) -> List[int]:
            lookup, pattern = {}, []
            idx = 0
            
            for ch in string:
                if ch in lookup:
                    pattern.append(lookup[ch])
                else:
                    idx += 1
                    lookup[ch] = idx
                    pattern.append(idx)
                    
            return pattern
        
        answer = []
        pattern_arr = parsePattern(pattern)

        for i in range(len(words)):
            if parsePattern(words[i]) == pattern_arr:
                answer.append(words[i])
        
        return answer
    
           
