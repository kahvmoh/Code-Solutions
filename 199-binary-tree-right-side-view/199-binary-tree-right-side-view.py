# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def rightSideView(self, root):
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
            lastElem = None
            for _ in range(numNode):
                node = q.popleft()
                lastElem = node.val
                if node.left is not None:
                    q.append(node.left)
                if node.right is not None:
                    q.append(node.right)
            result.append(lastElem)
        
        return result