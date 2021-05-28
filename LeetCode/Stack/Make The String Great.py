class Solution:
    def makeGood(self, s: str) -> str:
        stack = []
        
        for ch in s:
            if not stack:
                stack.append(ch)
            else:
                if ch.islower():
                    if ch.upper() == stack[-1]:
                        stack.pop()
                    else:
                        stack.append(ch)
                else:
                    if ch.lower() == stack[-1]:
                        stack.pop()
                    else:
                        stack.append(ch)
                        
        return "".join(map(str, stack))

