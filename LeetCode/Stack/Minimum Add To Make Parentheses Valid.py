class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        stack = []
        count = 0
        for ch in s:
            if not stack:
                stack.append(ch)
                count += 1
            else:
                if stack[-1] == '(' and ch == ')':
                    stack.pop()
                    count -= 1
                else:
                    stack.append(ch)
                    count += 1
        return count
