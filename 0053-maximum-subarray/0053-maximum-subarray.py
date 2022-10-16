class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        globalMax = nums[0]
        sofarMax = nums[0]
        
        for i in range(1, len(nums)):
            sofarMax = max(sofarMax + nums[i], nums[i])
            globalMax = max (globalMax, sofarMax)
        
        return globalMax