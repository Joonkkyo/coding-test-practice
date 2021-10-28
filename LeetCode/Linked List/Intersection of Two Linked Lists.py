# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        nodeA, nodeB = headA, headB
        list_A, list_B = [], []
        
        while nodeA.next:
            list_A.append(nodeA.val)
            nodeA = nodeA.next
        list_A.append(nodeA.val)
        
        while nodeB.next:
            list_B.append(nodeB.val)
            nodeB = nodeB.next
        list_B.append(nodeB.val)    
        
        len_A, len_B = len(list_A), len(list_B)
        tempA, tempB = headA, headB
        
        if len_A > len_B:
            for _ in range(len_A - len_B):
                tempA = tempA.next
            iteration = len_B
        else:
            for _ in range(len_B - len_A):
                tempB = tempB.next
            iteration = len_A
            
        while iteration:
            if tempA == tempB:
                return tempA
            
            tempA = tempA.next
            tempB = tempB.next
            iteration -= 1
            
        return None
            
