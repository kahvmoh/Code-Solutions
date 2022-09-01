# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def minDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root is None:
            return 0
        
        q = collections.deque([root])
        minDepth = 0
        
        while len(q) != 0:
            numNode = len(q)
            minDepth += 1
            for _ in range(numNode):
                node = q.popleft()
                if node.left is not None:
                    q.append(node.left)
                if node.right is not None:
                    q.append(node.right)
                if node.left is None and node.right is None:
                    return minDepth
                
            
            