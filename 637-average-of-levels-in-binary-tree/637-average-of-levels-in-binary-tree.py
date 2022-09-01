# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def averageOfLevels(self, root):
        """
        :type root: TreeNode
        :rtype: List[float]
        """
        if root is None:
            return []
        
        result = []
        
        q = collections.deque([root])
        
        while len(q) > 0:
            numNode = len(q)
            sum = 0.0
            for _ in range(numNode):
                node = q.popleft()
                if node.left is not None:
                    q.append(node.left)
                if node.right is not None:
                    q.append(node.right)
                sum += node.val
            result.append(sum/numNode)
            
        return result
        