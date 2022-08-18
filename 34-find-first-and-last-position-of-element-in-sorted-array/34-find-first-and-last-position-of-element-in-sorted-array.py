class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        start = 0
        end = len(nums) - 1
        first = -1
        last = -1
        
        
        while start <= end:
            mid = start + (end - start)/2
            if nums[mid] < target:
                start = mid + 1
            else:  # nums[mid] >= target
                end = mid - 1
        
        if start == len(nums) or nums[start] != target:
            return [first, last]
        
        leftmost = start
        end = len(nums) - 1
        
        while start <= end:
            mid = start + (end - start)/2
            if nums[mid] <= target:
                start = mid + 1
            else:  # nums[mid] > target
                end = mid - 1   
        
        return [leftmost, end]