class Solution(object):
    def singleNonDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        if len(nums) == 1:
            return nums[0]
        if nums[0] != nums[1]:
            return nums[0]
        if nums[-1] != nums[-2]:
            return nums[-1]
        
        start = 0
        end = len(nums) - 1
        
        while start <= end:
            mid = start + (end - start)/2
            
            if nums[mid] != nums[mid-1] and nums[mid] != nums[mid+1]:
                return nums[mid]
            elif (mid % 2 == 0 and nums[mid] == nums[mid+1]) or ( mid % 2 == 1 and nums[mid] == nums[mid-1]):
                start = mid + 1
            else:
                end = mid - 1
        
        
        