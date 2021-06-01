class Solution:
    def minOperations(self, logs: List[str]) -> int:
        stack = []
        
        for op in logs:
            if op == './':
                continue
            elif op == '../':
                if stack:
                    stack.pop()
            else:
                stack.append(op)
                
        return len(stack)
