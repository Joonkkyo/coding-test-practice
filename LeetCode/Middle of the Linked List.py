# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        node = head
        node_count = 0
        
        while node:
            node = node.next
            node_count += 1
        node_count //= 2
        
        for _ in range(node_count):
            head = head.next
            print(head)
        return head
            
