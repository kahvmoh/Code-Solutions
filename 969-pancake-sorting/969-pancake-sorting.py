class Solution(object):
    def pancakeSort(self, arr):
        """
        :type arr: List[int]
        :rtype: List[int]
        """
        result = []
        for i in range(len(arr)-1, -1, -1):
            if arr[i] != i+1:
                for j in range(i-1, -1, -1):
                    if arr[j] == i + 1:
                        break
                arr[:j+1] = arr[:j+1][::-1]        
                arr[:i+1] = arr[:i+1][::-1]
                
                result.append(j+1)
                result.append(i+1)
                
        return result