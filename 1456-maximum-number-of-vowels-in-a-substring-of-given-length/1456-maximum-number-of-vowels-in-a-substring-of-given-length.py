class Solution(object):
    def maxVowels(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        vowelset = set('aeiou')
        curvow = 0
        
        for i in range(k):
            if s[i] in vowelset:
                curvow += 1
                
        maxvow = curvow
        
        for i in range(k, len(s)):
            if s[i] in vowelset:
                curvow += 1
            if s[i-k] in vowelset:
                curvow -= 1
                
            maxvow = max(maxvow, curvow)
        
        return maxvow