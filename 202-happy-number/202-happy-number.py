class Solution(object):
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        
        if n == 1:
            return True
        
        def f(x):
            result  = 0
            
            while x != 0:
                result += (x % 10) ** 2
                x = x / 10
            return result
        
        fast = n
        slow = n
        
        while True:
            fast = f(f(fast))
            slow = f(slow)
            
            if fast == 1:
                return True
            elif slow == fast:
                return False
            
            
            
            
            
            
            
        
        