# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def detectCycle(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head is None:
            return None
        
        fast = head
        slow = head
        
        while fast.next is not None and fast.next.next is not None:
            fast = fast.next.next
            slow = slow.next
            
            if fast == slow:
                third = head
                while third != slow:
                    third = third.next
                    slow = slow.next
                return third
            
        return None
        