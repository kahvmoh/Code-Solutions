# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def zigzagLevelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if root is None:
            return []
        
        result = []
        l2r = True
        
        q = collections.deque([root])
        while len(q) != 0:
            temp = []
            numNodes = len(q)
            for _ in range(numNodes):
                node = q.popleft()
                temp.append(node.val)
                if node.left is not None:
                    q.append(node.left)
                if node.right is not None:
                    q.append(node.right)
            if l2r is False:
                temp.reverse()
            l2r = not l2r
            result.append(temp)
            
        return result
            