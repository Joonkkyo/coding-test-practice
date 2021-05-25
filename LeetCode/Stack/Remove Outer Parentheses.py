class Solution:
    def removeOuterParentheses(self, s: str) -> str:
        stack = []
        count = 0
        outer = False
        flag = True
        
        for ch in s:
            if ch == '(':
                stack.append(ch)
                count += 1
                if count >= 1 and flag:
                    stack.pop()
                    outer = True
                    flag = False
            else:
                stack.append(ch)
                count -= 1
                if outer and count == 0:
                    stack.pop()
                    outer = False
                    flag = True
                    
        return "".join(map(str, stack))
