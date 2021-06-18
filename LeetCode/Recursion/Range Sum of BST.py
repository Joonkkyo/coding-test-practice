# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rangeSumBST(self, root: TreeNode, low: int, high: int) -> int:
        answer = 0
        if not root: 
            return answer
        
        if low <= root.val <= high:
            answer += root.val
        
        answer += self.rangeSumBST(root.left, low, high)
        answer += self.rangeSumBST(root.right, low, high)
        
        return answer
