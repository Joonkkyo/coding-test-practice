class Solution:
    def removeDuplicates(self, s: str) -> str:
        stack = []
        for i in range(len(s)):
            if not stack:
                stack.append(s[i])
                top = stack[-1]

            else:
                if s[i] == top:
                    stack.pop()
                    if stack:
                        top = stack[-1]
                    else:
                        continue
                else:
                    stack.append(s[i])
                    top = stack[-1]
                    
        return ''.join(map(str, stack))
                     
