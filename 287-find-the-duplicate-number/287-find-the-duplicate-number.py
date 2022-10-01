class Solution(object):
    def findDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        for i in range(len(nums)):
            while nums[i] != i:
                d = nums[i]
                if nums[i] != nums[d]:
                    nums[i], nums[d] = nums[d], nums[i]
                else:
                    break
            for i in range(len(nums)):
                if nums[i] != i: 
                    return nums[i]
                

                
            
                
            
        
        