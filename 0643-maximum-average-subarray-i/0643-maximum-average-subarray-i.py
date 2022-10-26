class Solution(object):
    def findMaxAverage(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: float
        """
        maxSum = windowSum = sum(nums[:k])
        
        for i in range(k, len(nums)):
            windowSum = windowSum + nums[i] - nums[i-k]
            maxSum = max(maxSum, windowSum)

        return float(maxSum) / k 
        
        
    