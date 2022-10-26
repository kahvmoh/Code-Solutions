class Solution(object):
    def maxSatisfied(self, customers, grumpy, minutes):
        """
        :type customers: List[int]
        :type grumpy: List[int]
        :type minutes: int
        :rtype: int
        """
 
        numsatisfied = 0
        for i in range(len(customers)):
            if grumpy[i] == 0:
                numsatisfied += customers[i]
        
        numangry  = 0
        for i in range(minutes):
            if grumpy[i] == 1:
                numangry += customers[i]
                

        globalmaxangry = numangry
        for i in range(minutes, len(customers)):
            if grumpy[i] == 1:
                numangry += customers[i]
            if grumpy[i-minutes] == 1:
                numangry -= customers[i-minutes]
            globalmaxangry = max(globalmaxangry, numangry)
            
            
        return numsatisfied + globalmaxangry