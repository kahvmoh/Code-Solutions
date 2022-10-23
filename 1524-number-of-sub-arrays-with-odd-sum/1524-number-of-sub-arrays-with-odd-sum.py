class Solution(object):
    def numOfSubarrays(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        total = 0
        hmap = {}
        hmap["odd"] = 0
        hmap["even"] = 1
        pSum = 0
        
        for i in range(len(arr)):
            pSum += arr[i]
            
            if pSum % 2 == 0:
                total += hmap["odd"] 
            else:
                total += hmap["even"]
            
            total = total % 1000000007 
            
            if pSum % 2 == 0:
                hmap["even"] += 1
            else:
                hmap["odd"] += 1
        
        return total
            
            
            
            