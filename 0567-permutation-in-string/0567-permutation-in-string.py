class Solution(object):
    def checkInclusion(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        if len(s2) < len(s1):
            return False
        
        k = len(s1)
        hmap_s1 = {}
        for i in range(k):
            if s1[i] in hmap_s1:
                hmap_s1[s1[i]] += 1
            else:
                hmap_s1[s1[i]] = 1

        hmap_s2 = {}
        for i in range(k):
            if s2[i] in hmap_s2:
                hmap_s2[s2[i]] += 1
            else:
                hmap_s2[s2[i]] = 1
        
        if hmap_s1 == hmap_s2:
            return True
        
        # check the rest of s2 for any other permutation of s1
        for i in range(k, len(s2)):
            # remove the char going out of window
            hmap_s2[s2[i-k]] -= 1
            if hmap_s2[s2[i-k]] == 0:
                del hmap_s2[s2[i-k]]
            
            if s2[i] in hmap_s2:
                hmap_s2[s2[i]] += 1
            else:
                hmap_s2[s2[i]] = 1
                
            if hmap_s1 == hmap_s2:
                return True
        
        return False
                