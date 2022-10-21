class Solution(object):
    def subarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        hmap = {}
        
        hmap[0] = 1
        
        total = 0
        prefixSum = 0
        
        for i in range(len(nums)):
            prefixSum += nums[i]
            
            if prefixSum - k in hmap:
                total += hmap[prefixSum-k]
            if prefixSum in hmap:
                hmap[prefixSum] += 1
            else:
                hmap[prefixSum] = 1
        
        return total
        