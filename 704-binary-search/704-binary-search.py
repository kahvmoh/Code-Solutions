class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        
        def helper(A, start, end, target):
            if start > end:
                return -1
            
            mid = start + ( (end - start) / 2)
            
            if A[mid] == target:
                return mid
            elif nums[mid] < target:
                return helper(A, mid + 1, end, target)
            else:
                return helper(A, start, mid - 1, target)
        
        return helper(nums, 0, len(nums) -1, target)