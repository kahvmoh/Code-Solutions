class Solution(object):
    def runningSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        
        results = []
        sum = 0
        
        for i in range(len(nums)):
            sum += nums[i]
            results.append(sum)
        
        return results