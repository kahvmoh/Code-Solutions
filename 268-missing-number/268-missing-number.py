class Solution(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        for i in range(len(nums)):
            while nums[i] != i:
                d = nums[i]
                if d < len(nums):
                    nums[i], nums[d] = nums[d], nums[i]
                else:
                    break
        
        for i in range(len(nums)):
            if nums[i] == len(nums):
                return i
        
        return len(nums)
    