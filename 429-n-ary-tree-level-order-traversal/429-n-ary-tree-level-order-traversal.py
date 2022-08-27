"""
# Definition for a Node.
class Node(object):
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution(object):
    def levelOrder(self, root):
        """
        :type root: Node
        :rtype: List[List[int]]
        """
        if root is None:
            return []
        
        result = []
        q = collections.deque([root])
        while len(q) != 0:
            temp = []
            numNodes = len(q)
            for _ in range(numNodes):
                node = q.popleft()
                temp.append(node.val)
                for child in node.children:
                    q.append(child)
            result.append(temp)
        
        return result
                               
        