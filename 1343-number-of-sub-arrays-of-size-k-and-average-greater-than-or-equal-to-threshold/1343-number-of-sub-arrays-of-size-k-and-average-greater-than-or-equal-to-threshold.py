class Solution(object):
    def numOfSubarrays(self, arr, k, threshold):
        """
        :type arr: List[int]
        :type k: int
        :type threshold: int
        :rtype: int
        """
        winSum = sum(arr[:k])
        
        count = 0
        if float(winSum) / k >= threshold:
            count += 1
        
        for i in range(k, len(arr)):
            winSum = winSum + arr[i] - arr[i-k]
            if float(winSum) / k >= threshold:
                count += 1
        
        return count