class Solution(object):
    def dietPlanPerformance(self, calories, k, lower, upper):
        """
        :type calories: List[int]
        :type k: int
        :type lower: int
        :type upper: int
        :rtype: int
        """
        points = 0
        winSum = sum(calories[:k])
        
        if winSum < lower:
            points -= 1
        elif winSum > upper:
            points += 1
        
        for i in range(k, len(calories)):
            winSum = winSum + calories[i] - calories[i-k]
            if winSum < lower:
                points -= 1
            elif winSum > upper:
                points += 1
                
        return points