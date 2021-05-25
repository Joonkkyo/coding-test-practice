class Solution:
    def removeDuplicates(self, s: str, k: int) -> str:
        stack = []
        answer = ""
        for i in range(len(s)):
            if not stack:
                stack.append((s[i], 1))
            else:
                if stack[-1][0] == s[i]:
                    stack.append((s[i], stack[-1][1] + 1))
                    
                    if stack[-1][1] == k:
                        for _ in range(k):
                            stack.pop()
                else:
                    stack.append((s[i], 1))
            
        for i in range(len(stack)):
            answer += stack[i][0]
            
        return answer
