class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        stack_s, stack_t = [], []
        for ch in s:
            if not stack_s:
                if ch != '#':
                    stack_s.append(ch)
                else:
                    continue
            elif ch == '#':
                stack_s.pop()
            else:
                stack_s.append(ch)
                
        for ch in t:
            if not stack_t:
                if ch != '#':
                    stack_t.append(ch)
                else:
                    continue
            elif ch == '#':
                stack_t.pop()
            else:
                stack_t.append(ch)
                
        ans_s = ''.join(map(str, stack_s))
        ans_t = ''.join(map(str, stack_t))

        return ans_s == ans_t
