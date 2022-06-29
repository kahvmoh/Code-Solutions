# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def middleNode(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        fast = head
        slow = head
        
        while fast.next is not None and fast.next.next is not None:
            fast = fast.next.next
            slow = slow.next
            
        if fast.next is not None:
            slow = slow.next
            
        return slow
        
        
        