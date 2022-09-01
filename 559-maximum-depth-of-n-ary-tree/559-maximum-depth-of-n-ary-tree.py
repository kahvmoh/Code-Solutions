"""
# Definition for a Node.
class Node(object):
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution(object):
    def maxDepth(self, root):
        """
        :type root: Node
        :rtype: int
        """
        if root is None:
            return 0
        
        level = 0;
        q = collections.deque([root])
        
        while len(q) != 0 :
            numNode = len(q)
            level += 1
            for _ in range(numNode):
                node = q.popleft()
                for child in node.children:
                    q.append(child)
        
        return level