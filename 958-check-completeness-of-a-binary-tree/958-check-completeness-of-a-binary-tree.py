# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isCompleteTree(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if root is None: 
            return True
        
        q = collections.deque([(root, 1)])
        expectedId = 1
        
        while len(q) != 0:
            numNodes = len(q)
            
            for _ in range(numNodes):
                (node, id) = q.popleft()
                if expectedId == id:
                    expectedId += 1
                else:
                    return False
                
                if node.left is not None:
                   q.append((node.left, id*2))
                if node.right is not None:
                    q.append((node.right, id*2 + 1))
        
        return True
                
                
            
        