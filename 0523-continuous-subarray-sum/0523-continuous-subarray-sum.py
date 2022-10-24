class Solution(object):
    def checkSubarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        if len(nums) < 2:
            return False
        
        if k == 0:
            for i in range(1, len(nums)):
                if nums[i-1] == number[i] == 0:
                    return True
            return False
        
        hmap = {}
        hmap[0] = True
        PSumOld = nums[0]
        pSum = nums[0]
        
        for i in range(1, len(nums)):
            pSumOld = pSum
            pSum = (pSum + nums[i]) % k
            
            if pSum in hmap:
                return True
            hmap[pSumOld % k] = True
        
        return False
        
        