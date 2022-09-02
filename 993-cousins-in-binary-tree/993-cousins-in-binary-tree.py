# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isCousins(self, root, x, y):
        """
        :type root: TreeNode
        :type x: int
        :type y: int
        :rtype: bool
        """
        if root is None:
            return False
        
        q = collections.deque([root])
        px = None
        py = None
        
        while len(q) != 0:
            numNode = len(q)
            
            for _ in range(numNode):
                node = q.popleft()
                if node.left is not None:
                    q.append(node.left)
                    if node.left.val == x:
                        px = node.val
                    if node.left.val == y:
                        py = node.val
                if node.right is not None:
                    q.append(node.right)
                    if node.right.val == x:
                        px = node.val
                    if node.right.val == y:
                        py = node.val
            if px is not None or py is not None:
                return px is not None and py is not None and px != py
        
                        
            