class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        answer = []
        position = [0 for _ in range(26)]
    
        for i in range(len(s)):
            position[ord(s[i]) - ord('a')] = i
            
        start, end = 0, 0
        for i in range(len(s)):
            end = max(position[ord(s[i]) - ord('a')], end)
            if i == end:
                answer.append(end - start + 1)
                start = i + 1
                
        return answer
