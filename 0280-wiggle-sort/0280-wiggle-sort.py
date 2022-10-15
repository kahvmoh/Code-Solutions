class Solution(object):
    def wiggleSort(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        for i in range(1, len(nums)):
            if (i & 1 == 0 and nums[i-1] < nums[i]) or (i & 1 == 1 and nums[i-1] > nums[i]):
                nums[i-1], nums[i] = nums[i], nums[i-1]
        
        return nums