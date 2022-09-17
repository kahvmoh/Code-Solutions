# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if root is None:
            return True
        
        q = collections.deque([(root, root)])
        while len(q) != 0:
            numNodes = len(q)
            
            for _ in range(numNodes):
                nodeL,nodeR = q.popleft()
                
                if nodeL.left is not None and nodeR.right is not None:
                    q.append((nodeL.left, nodeR.right))
                elif nodeL.left is not None or nodeR.right is not None:    
                        return False

                if nodeL.right is not None and nodeR.left is not None:
                    q.append((nodeL.right, nodeR.left))
                elif nodeL.right is not None or nodeR.left is not None:    
                        return False
                
                if nodeL.val != nodeR.val:
                    return False

        return True
    
    
        