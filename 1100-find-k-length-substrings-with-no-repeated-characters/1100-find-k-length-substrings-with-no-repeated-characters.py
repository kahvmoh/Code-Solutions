class Solution(object):
    def numKLenSubstrNoRepeats(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        if k > len(s):
            return 0
        
        hmap = {}
        
        for i in range(k):
            if s[i] in hmap:
                hmap[s[i]] += 1
            else: 
                hmap[s[i]] = 1
        
        if len(hmap) == k:
            strcount = 1
        else:
            strcount = 0
        
        for i in range(k, len(s)):
            if s[i] in hmap:
                hmap[s[i]] += 1
            else:
                hmap[s[i]] = 1
            
            hmap[s[i-k]] -= 1
            if hmap[s[i-k]] == 0:
                del hmap[s[i-k]]
            
            if len(hmap) == k:
                strcount += 1
       
        return strcount
            
            