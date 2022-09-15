# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def addOneRow(self, root, val, depth):
        """
        :type root: TreeNode
        :type val: int
        :type depth: int
        :rtype: TreeNode
        """
        
        if depth == 1 :
            newNode = TreeNode(val)
            newNode.left = root
            root = newNode
            return root
        
        q = collections.deque([root])
        level = 0
        
        while len(q) != 0:
            numNode = len(q)
            level += 1
            
            for _ in range(numNode):
                node = q.popleft()
                if node.left is not None:
                    q.append(node.left)
                if node.right is not None:
                    q.append(node.right)
                if level == depth - 1:
                    newLeft = TreeNode(val)
                    newRight = TreeNode(val)
                    newLeft.left = node.left
                    newRight.right = node.right
                    node.left = newLeft
                    node.right = newRight
        
        return root
                