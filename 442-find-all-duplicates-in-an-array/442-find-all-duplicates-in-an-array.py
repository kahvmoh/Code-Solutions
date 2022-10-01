class Solution(object):
    def findDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        
        result = []
        
        for i in range(len(nums)):
            while nums[i] != i + 1:
                d = nums[i] - 1
                if nums[i] != nums[d]:
                    nums[i], nums[d] = nums[d], nums[i]
                else:
                    break
        
        for i in range(len(nums)):
            if nums[i] != i + 1:
                result.append(nums[i])
        
        return result
        