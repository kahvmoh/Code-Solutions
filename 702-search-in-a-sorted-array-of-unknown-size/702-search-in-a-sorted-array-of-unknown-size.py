# """
# This is ArrayReader's API interface.
# You should not implement it, or speculate about its implementation
# """
#class ArrayReader(object):
#    def get(self, index):
#        """
#        :type index: int
#        :rtype int
#        """

class Solution(object):
    def search(self, reader, target):
        """
        :type reader: ArrayReader
        :type target: int
        :rtype: int
        """
        end = 1
        while reader.get(end) < target:
            end = end * 2
        start = end / 2
        
        while start <= end:
            mid = start + (end - start) / 2
            if reader.get(mid) == target:
                return mid
            elif reader.get(mid) < target:
                start = mid + 1
            else:
                end = mid - 1
        
        return -1
    
    