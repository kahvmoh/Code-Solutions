# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        sentinel = ListNode(float("-inf"), head)
        
        cur = head
        prev = sentinel        
        while cur is not None:
            if cur.next is not None and  cur.val == cur.next.val:
                val = cur.val
                while cur.next is not None and val == cur.next.val:
                    cur = cur.next
                
                prev.next = cur.next
                cur = cur.next
            else:
                prev = cur
                cur = cur.next
        
        return sentinel.next
    
                