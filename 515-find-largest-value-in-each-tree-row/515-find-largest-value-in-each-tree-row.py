# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def largestValues(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if root is None:
            return []
        result = []
        
        q = collections.deque([root])
        while len(q) > 0:
            numNode = len(q)
            rowMax = float("-inf")
            for _ in range(numNode):
                node = q.popleft()
                if node.left is not None:
                    q.append(node.left)
                if node.right is not None:
                    q.append(node.right)
                #if rowMax < node.val:
                rowMax = max(rowMax, node.val)
            result.append(rowMax)
        
        return result
        