class Solution(object):
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        for i in range(len(nums)):
            while nums[i] != i + 1:
                d = nums[i] - 1
                if 0 <= d < len(nums) and nums[i] != nums[d]:
                    nums[i], nums[d] = nums[d], nums[i]
                else:
                    break;
                    
        for i in range(len(nums)):
            if nums[i] != i + 1:
                return i + 1
        
        return len(nums)+1
            
        