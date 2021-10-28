# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def deepestLeavesSum(self, root: Optional[TreeNode]) -> int:
        answer = 0
        
        def findMaxDepth(node):
            if not node: return 0
            return max(findMaxDepth(node.left), findMaxDepth(node.right)) + 1
                
        max_depth = findMaxDepth(root)
        dq = deque([(root, 1)])
        
        while dq:
            node, depth = dq.popleft()
            if node.left:
                dq.append((node.left, depth + 1))
            if node.right:
                dq.append((node.right, depth + 1))
                
            if depth == max_depth:
                answer += node.val
                
        return answer
