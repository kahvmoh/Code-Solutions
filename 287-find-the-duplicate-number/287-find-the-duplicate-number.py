class Solution(object):
    def findDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        def f(x):
            return nums[x]
        
        fast = 0
        slow = 0
        
        while True:
            fast = f(f(fast))
            slow = f(slow)
            
            if fast == slow:
                third = 0
                while third != slow:
                    slow = f(slow)
                    third = f(third)
                return third
            
                
            
        
        