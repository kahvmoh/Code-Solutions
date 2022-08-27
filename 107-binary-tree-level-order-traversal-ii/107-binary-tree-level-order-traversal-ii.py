# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def levelOrderBottom(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        
        if root is None:
            return []
        result = collections.deque()
        q = collections.deque([root])
        
        while len(q) != 0:
            numNodes = len(q)
            temp = []
            for _ in range(numNodes):
                node = q.popleft()
                temp.append(node.val)
                if node.left is not None:
                    q.append(node.left)
                if node.right is not None:
                    q.append(node.right)
                    
            result.appendleft(temp)
        
        return result
            