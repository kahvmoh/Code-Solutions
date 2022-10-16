class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        minRow = 0
        maxCol = len(matrix[0]) - 1
        
        while minRow < len(matrix) and maxCol >= 0:
            if matrix[minRow][maxCol] == target:
                return True
            elif target < matrix[minRow][maxCol]:
                maxCol -= 1
            else:
                minRow += 1
        
        return False