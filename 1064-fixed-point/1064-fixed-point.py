class Solution(object):
    def fixedPoint(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        start = 0
        end = len(arr) - 1
        
        while start <= end:
            mid = start + (end - start)/2
            if arr[mid] < mid:
                start  = mid + 1
            else:
                end = mid - 1
                
        if start < len(arr) and arr[start] == start:
            return start
        else:
            return -1
            
            