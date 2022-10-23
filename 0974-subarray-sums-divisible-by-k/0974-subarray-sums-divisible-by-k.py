class Solution(object):
    def subarraysDivByK(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        hmap = {}
        
        hmap[0] = 1
        
        total = 0
        pSum = 0
        
        for i in range(len(nums)):
            pSum = (pSum + nums[i]) % k
            
            if pSum in hmap:
                total += hmap[pSum]
            if pSum in hmap:
                hmap[pSum] += 1
            else:
                hmap[pSum] = 1
        
        return total