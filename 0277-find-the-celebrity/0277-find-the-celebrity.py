# The knows API is already defined for you.
# @param a, person a
# @param b, person b
# @return a boolean, whether a knows b
# def knows(a, b):

class Solution(object):
    def findCelebrity(self, n):
        """
        :type n: int
        :rtype: int
        """
        # Eliminate non-celebrities
        sur = 0
        for i in range(1, n):
            if knows(sur, i):
                sur = i
        
        # verify if sur is a celebrity
        for i in range(n):
            if sur != i and (knows(sur, i) or not knows(i, sur)):
                return -1
        
        return sur
            
    