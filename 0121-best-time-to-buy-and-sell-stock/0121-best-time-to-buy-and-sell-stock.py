class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if len(prices) == 0:
            return 0
        
        globalMax = 0
        leastPrice = prices[0]
        
        for i in range(1, len(prices)):
            if prices[i] - leastPrice > globalMax:
                globalMax = prices[i] - leastPrice
            leastPrice = min(leastPrice, prices[i])
            
        return globalMax