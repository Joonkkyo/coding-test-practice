class Solution:
    def diStringMatch(self, s: str) -> List[int]:
        answer = []
        min_val, max_val = 0, len(s)
        
        for i in range(len(s)):
            if s[i] == 'I':
                answer.append(min_val)
                min_val += 1
            else:
                answer.append(max_val)
                max_val -= 1
        
        answer.append(max_val)
        return answer
