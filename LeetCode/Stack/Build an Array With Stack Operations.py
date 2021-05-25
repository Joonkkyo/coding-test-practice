class Solution:
    def buildArray(self, target: List[int], n: int) -> List[str]:
        stack = []
        num_list = [i + 1 for i in range(n)]
        idx = 0
        
        for i in range(n):
            if target[idx] == num_list[i]:
                stack.append("Push")
                idx += 1
            else:
                stack.append("Push")
                stack.append("Pop")
            if idx == len(target):
                break
                
        return stack
