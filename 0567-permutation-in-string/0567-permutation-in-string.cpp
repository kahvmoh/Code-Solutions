class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        unordered_map<char, int> hmap_s1, hmap_s2;
        
        if (s2.length() < s1.length())
            return false;
        
        int k = s1.size();
        
        // populate the first hash map for the first section of the string
        for( int i = 0; i < k; i++) {
            if (hmap_s1.find(s1[i]) == hmap_s1.end())
                hmap_s1[s1[i]] = 1;
            else
                hmap_s1[s1[i]] += 1;
        }
        
        // populate the second hash map
        for( int i = 0; i < k; i++) {
            if (hmap_s2.find(s2[i]) == hmap_s2.end())
                hmap_s2[s2[i]] = 1;
            else
                hmap_s2[s2[i]] += 1;
        }
        
        if (hmap_s1 == hmap_s2)
                return true;
        

        for (int i = k; i < s2.size(); i++) {
            // deleting the char going out of window
            if (hmap_s2[s2[i-k]] > 1)
                hmap_s2[s2[i-k]] -= 1;
            else
                hmap_s2.erase(s2[i-k]);
            // adding the new char
            if (hmap_s2.find(s2[i]) == hmap_s2.end())
                hmap_s2[s2[i]] = 1;
            else
               hmap_s2[s2[i]] += 1;
            
            if (hmap_s1 == hmap_s2)
                return true;
        }
        
        return false;
        
    }
};