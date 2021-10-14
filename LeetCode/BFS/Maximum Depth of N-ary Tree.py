"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def maxDepth(self, root: 'Node') -> int:
        if not root:
            return 0
        queue = []
        queue.append((root, 1))
        
        while queue:
            node, depth = queue.pop(0) 
            for child in node.children:
                queue.append((child, depth + 1))
     
        return depth
    
#         ## DFS
#         if not root:
#             return 0
        
#         depth = 0

#         for child in root.children:
#             depth = max(depth, self.maxDepth(child))
            
#         return depth + 1 
        
