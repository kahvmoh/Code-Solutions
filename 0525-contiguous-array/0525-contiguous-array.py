class Solution(object):
    def findMaxLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        gMax = 0
        hmap = {}
        hmap[0] = 0
        pSum = 0
        
        for i in range(len(nums)):            
            if nums[i] == 1:
                pSum += 1 
            else:
                pSum -= 1
                
            if pSum in hmap:
                gMax = max(gMax, i+1 - hmap[pSum]) 
            
            if pSum not in hmap:
                hmap[pSum] = i + 1
        
        return gMax