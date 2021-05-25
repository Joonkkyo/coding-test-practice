# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        slow, fast = head, head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
  
        prev, cur = None, slow
        while cur:
            next = cur.next
            cur.next = prev
            prev, cur = cur, next

        while prev:
            if prev.val != head.val:
                return False
            else:
                head, prev = head.next, prev.next
        return True
