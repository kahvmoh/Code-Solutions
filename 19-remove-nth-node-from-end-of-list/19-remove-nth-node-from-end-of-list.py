# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        
        sentinel = ListNode(float("-inf"), head)
        
        leader = head
        for _ in range(n):
            leader = leader.next
        cur = head
        prev = sentinel
  
        while leader is not None:
            leader = leader.next
            prev = cur
            cur = cur.next
        
        prev.next = cur.next
        
        return sentinel.next
        