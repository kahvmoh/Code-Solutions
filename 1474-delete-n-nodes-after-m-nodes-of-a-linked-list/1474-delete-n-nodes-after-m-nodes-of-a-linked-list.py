# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def deleteNodes(self, head, m, n):
        """
        :type head: ListNode
        :type m: int
        :type n: int
        :rtype: ListNode
        """
        sentinel = ListNode(0, head)
        cur = head
        prev = sentinel
        
        while cur is not None:
            i = 1
            while cur is not None and i <= m:
                prev = cur
                cur = cur.next
                i += 1
                
            if cur is None:
                break;
                
            j = 1
            while cur is not None and j <= n:
                cur = cur.next
                j += 1
            
            prev.next = cur
        
        return sentinel.next
    
        