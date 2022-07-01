"""
# Definition for a Node.
class Node(object):
    def __init__(self, val=None, next=None):
        self.val = val
        self.next = next
"""

class Solution(object):
    def insert(self, head, insertVal):
        """
        :type head: Node
        :type insertVal: int
        :rtype: Node
        """
        
        node = ListNode(insertVal, None)
        if head is None:
            node.next = node
            return node
        elif head.next == head:
            node.next = head
            head.next = node
            return head
        
        cur = head.next
        prev = head
        while cur.val >= prev.val and cur != head:
            cur = cur.next
            prev = prev.next
            
        #cur is at the smallest value in the circular list
        if insertVal > prev.val:
            prev.next = node
            node.next = cur
            return head
        
        while cur.val < insertVal:
            cur = cur.next
            prev = prev.next
        
        prev.next = node
        node.next = cur
        return head
    
		