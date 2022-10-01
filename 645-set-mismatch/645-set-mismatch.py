class Solution(object):
    def findErrorNums(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        #result = []
        
        for i in range(len(nums)):
            while nums[i] != i + 1:
                d = nums[i] - 1
                if nums[i] != nums[d]:
                    nums[i], nums[d] = nums[d], nums[i]
                else:
                    break
        
        for i in range(len(nums)):
            if nums[i] != i + 1:
                return [nums[i], i + 1]
            
                    