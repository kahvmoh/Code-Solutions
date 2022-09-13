"""
# Definition for a Node.
class Node(object):
    def __init__(self, val=0, left=None, right=None, next=None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution(object):
    def connect(self, root):
        """
        :type root: Node
        :rtype: Node
        """
        if root is None:
            return None
        
        q = collections.deque([root])
        while len(q) != 0:
            numNode = len(q)
            prev = None
            for _ in range(numNode):
                node = q.popleft()
                if node.left is not None:
                    q.append(node.left)
                if node.right is not None:
                    q.append(node.right)
                if prev is not None:
                    prev.next = node
                prev = node
        
        return root
        