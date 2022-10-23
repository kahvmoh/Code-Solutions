class Solution(object):
    def maxSubArrayLen(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        hmap = {}
        hmap[0] = 0
        
        gMax = 0
        pSum = 0
        
        for i in range(len(nums)):
            pSum += nums[i]
            
            if pSum - k in hmap:
                gMax = max(gMax, i + 1 - hmap[pSum-k])
            if pSum not in hmap:
                hmap[pSum] = i + 1
        
        return gMax