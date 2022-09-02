# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def maxLevelSum(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        
        if root is None:
            return 0

        maxSum = float("-inf")
        minLevel = 0
        level = 0
        
        q = collections.deque([root])
        while len(q) != 0:
            numNode = len(q)
            level += 1
            levelSum = 0
            for _ in range(numNode):
                node = q.popleft()
                levelSum += node.val
                if node.left is not None:
                    q.append(node.left)
                if node.right is not None:
                    q.append(node.right)
            if levelSum > maxSum:
                maxSum = levelSum
                minLevel = level 
            
        return minLevel
    
    
                  
            
        