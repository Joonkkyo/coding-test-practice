class Solution:
    def calPoints(self, ops: List[str]) -> int:
        stack = []
        answer = 0
        
        for op in ops:
            if op == 'C':
                stack.pop()
            elif op == 'D':
                stack.append(stack[-1] * 2)
            elif op == '+':
                stack.append(stack[-1] + stack[-2])
            else:
                stack.append(int(op))
                
        for score in stack:
            answer += score
            
        return answer
            
