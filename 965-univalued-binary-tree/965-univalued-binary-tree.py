# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isUnivalTree(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if root is None:
            return true
        
        uniVal = root.val
        q = collections.deque([root])
        
        while len(q) != 0:
            numNode = len(q)
            
            for _ in range(numNode):
                node = q.popleft()
                if node.val != uniVal:
                    return False
                if node.left is not None:
                    q.append(node.left)
                if node.right is not None:
                    q.append(node.right)
        return True